#include "funciones.h"

void reset_amen(ptrClose *closed, ptrOpen *open) 
{
	int fila, colu;

	for (fila=0; fila<=MAX; fila++) {
		for (colu=0; colu<=MAX; colu++) 
			posic[fila][colu]= False;
	}
	while (closed!=NULL) {
		fila= closed->fila;
		colu= closed->colu;
		amenazar(fila, colu);
		closed= closed->back;
	}
	if (open!=NULL) {
		fila= open->fila;
		colu= open->colu;
		amenazar(fila, colu);
	}
}

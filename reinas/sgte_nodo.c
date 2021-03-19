#include "funciones.h"

ptrClose *sgte_nodo(ptrClose *closed)
{
	if (closed->hijos==1) {
		while(closed->hijos==1)
			closed= closed->back;
	}
	else
		closed->hijos--;
	
	return closed;
}

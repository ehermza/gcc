#include "funciones.h"

ptrOpen *casillas_libres(int factual)
{
	int colum, fsgte;
	ptrOpen *open=NULL, *nuevo, *inicio;

	fsgte= factual+ 1;

	for (colum=1; colum<=MAX; colum++) {
		if (!posic[fsgte][colum]) {
			if (open!=NULL) {
				nuevo= (ptrOpen*)malloc(sizeof(ptrOpen));
				nuevo->fila= fsgte;
				nuevo->colu= colum;
				open ->sgte= nuevo;
				open= open->sgte;
			}
			else {	
				inicio= (ptrOpen*)malloc(sizeof(ptrOpen));
				inicio->fila= fsgte;
				inicio->colu= colum;
				open = inicio;
			}
		}
	}
	if (open==NULL) return NULL;

	return inicio;
}

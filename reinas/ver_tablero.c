#include <stdio.h>
#include "funciones.h"

void ver_tablero(ptrOpen *open, ptrClose *closed) {
	int fila, colu;
	
	printf("\ncamino:");
	while (closed!=NULL){
		fila= closed->fila;
		colu= closed->colu;
		printf(" (%d,%d)", fila, colu); 
		closed= closed->back;
	}
	
	printf("\n  open:");
	while (open!=NULL){
		fila= open->fila;
		colu= open->colu;
		printf(" (%d,%d)", fila, colu); 
		open= open->sgte;
	}
	
	for (fila=1; fila<=MAX; fila++) {
		printf("\n\t\t");
		for (colu=1; colu<=MAX; colu++) 
			printf("|%c|", posic[fila][colu]+'0');
	}

}

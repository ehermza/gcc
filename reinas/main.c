#include <stdio.h>
#include "funciones.h"

int fila_actual(ptrOpen *open) { 
	if (open==NULL) return 0;
	return open->fila; 
}

int main()
{
	int size, factual, exito, start;
	ptrOpen *open=NULL, *nuevos;
	ptrClose *closed=NULL;

	exito= False;
	start= True;

	while ((open!=NULL || start) && !exito )  
	{
		reset_amen(closed, open);
		factual= fila_actual(open);
		nuevos= casillas_libres(factual);

		if (nuevos!=NULL) {
			ver_tablero(open, closed);
			size= contar_hijos(nuevos);
			closed= add_closed(closed, open, size);
			open= add_open(open, nuevos);
		} else {
			ver_tablero(open, closed);
			closed= sgte_nodo(closed);
			open= open->sgte;
		}
		exito = es_objetivo(open);
		start = False;
	}

	if ( exito ) {
		closed= add_closed(closed, open, False);
		mostrar_resp(closed);
	}
	else 
		printf("\nESTE PROBLEMA NO TIENE SOLUCION\n");

	return 0;
}


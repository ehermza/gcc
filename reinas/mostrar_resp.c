#include <stdio.h>
#include "funciones.h"

void mostrar_resp(ptrClose *closed) 
{
	reset_amen(closed, NULL);
	ver_tablero(NULL, closed);
	printf("\nMUY BIEN!: Encontre una solucion\n\n");
	
}

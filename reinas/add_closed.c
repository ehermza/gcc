#include "funciones.h"

ptrClose *add_closed(ptrClose *closed, ptrOpen *open, int dispon)
{
	ptrClose *nuevo= malloc(sizeof(ptrClose)); 
	
	if (closed!=NULL) 
	{
		nuevo->fila= open->fila;
		nuevo->colu= open->colu;
		nuevo->back= closed;
	}
	nuevo->hijos= dispon;

	return nuevo;
}

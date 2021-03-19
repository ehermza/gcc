#include "funciones.h"

int es_objetivo(ptrOpen *open) {
	int valor= False;

	if (open==NULL) return False;
	if (open->fila==MAX) valor= True;

	return valor;
}

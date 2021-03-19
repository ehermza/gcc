#include "funciones.h"

ptrOpen *add_open(ptrOpen *oldOpen, ptrOpen *newOpen)
{	
	ptrOpen *inicio= newOpen;

	if (oldOpen==NULL) return newOpen;
	if (newOpen==NULL) return oldOpen->sgte;
	
	while (newOpen->sgte!=NULL)
		newOpen= newOpen->sgte;
	
	newOpen->sgte= oldOpen->sgte;

	return inicio;
}

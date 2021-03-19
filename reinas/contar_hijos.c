#include "funciones.h"

int contar_hijos(ptrOpen *nuevo) {
	int contad=0;

	while (nuevo!=NULL) {
		contad++;
		nuevo= nuevo->sgte;
	}
	return contad;
}

#include "funciones.h"

void amenazar(int fila, int colu) {
	amen_ctr(fila, colu);
	amen_diag_izq(fila, colu);
	amen_diag_der(fila, colu);
	posic[fila][colu]= Ficha;
}

void amen_diag_izq(int fila, int colu) {
	if (!prohibido(fila+1, colu-1))
		amen_diag_izq(fila+1, colu-1);
	posic[fila][colu]= True;
}

void amen_ctr(int fila, int colu) {
	if (!prohibido(fila+1, colu))
		amen_ctr(fila+1, colu);
	posic[fila][colu]= True;
}

void amen_diag_der(int fila, int colu) {
	if (!prohibido(fila+1, colu+1))
		amen_diag_der( fila+1, colu+1);
	posic[fila][colu]= True;
}

int prohibido(int fila, int colu) {
	if (fila > MAX  || fila < 1) return True;
	if (colu > MAX  || colu < 1) return True;
	return False;
}

#include <stdlib.h>
#define False 0
#define True 1
#define Ficha -13
#define MAX 4 

typedef struct Open {
	int fila;
	int colu;
	struct Open *sgte;
} ptrOpen;

typedef struct Closed {
	int fila;
	int colu;
	int hijos;
	struct Closed *back;
} ptrClose;

int posic[MAX+1][MAX+1];

void reset_amenazas(ptrClose *closed, ptrOpen *open);
void amenazar(int fila, int colu);
void amen_ctr(int fila, int colu);
void amen_diag_izq(int fila, int colu);
void amen_diag_der(int fila, int colu);

ptrClose *add_closed(ptrClose *closed, ptrOpen *open, int size);
ptrClose *sgte_nodo(ptrClose *closed);
ptrOpen *add_open(ptrOpen *oldOpen, ptrOpen *newOpen);
ptrOpen *casillas_libres(int factual);

int contar_hijos(ptrOpen *nuevo);
int es_objetivo(ptrOpen *open);
void ver_tablero(ptrOpen *open, ptrClose *closed);
void mostrar_resp(ptrClose *closed);

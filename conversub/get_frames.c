
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

long get_frame(char *tiempo)
{
	char *ptro= tiempo;	
	int horas= atol(ptro);
	ptro+=3;

	int minut= atol(ptro);
	ptro+=3;

	float sgndos= atof(ptro);

	double total= ((horas* 60) + minut)* 60 + sgndos;
//	printf("%.0003f segundos\n", total);
	
	long cuadros= total * fps;
//	printf("%d\n", cuadros);
	return cuadros;
}

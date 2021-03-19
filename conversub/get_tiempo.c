#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

char *get_tiempo(long frames)
{
//	long frames=112023;
	double inicio= frames/fps;

	double calc= inicio/ 60;
	int entero= calc;
	double sgndos= (calc -entero)*60;

	int seg_ent= sgndos;
	double mseg= (sgndos -seg_ent)*1000;

	inicio= entero;
	calc= inicio/ 60;
	int horas= calc;
	float temp= (calc -horas)*60;
	int minut= temp;

	if (mseg > 999) {
		mseg= 0; seg_ent= seg_ent+ 1;
		if (seg_ent > 59) {
			seg_ent= 0; minut= minut+ 1;
			if (minut > 59) {
				minut= 0; horas= horas+ 1;
			}	
		}
	}
	
	char *tiempo= malloc(sizeof(char)*16);
	sprintf(tiempo, "%002d:%002d:%002d,%0003.f", 
		horas, minut, seg_ent, mseg);
//	puts(tiempo);
	return tiempo;
}

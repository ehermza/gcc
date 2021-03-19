#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

char *sub_to_srt(Sub prfo)
{
	int id= prfo.numero;

	char *frase_1= prfo.frase_uno;
	char *frase_2= prfo.frase_dos;

	char *oracion= malloc(sizeof(char)*256);
	
	char *time_uno= get_tiempo(prfo.frame_uno);
	char *time_dos= get_tiempo(prfo.frame_dos);

	if ( !strlen(frase_2) ) {
		sprintf(oracion, "%d\r\n%s --> %s\r\n%s\r\n\r\n", 
			id, time_uno, time_dos, frase_1);
	}
	else {
		sprintf(oracion, "%d\r\n%s --> %s\r\n%s\r\n%s\r\n\r\n", 
			id, time_uno, time_dos, frase_1, frase_2);
	}

	return oracion;
}

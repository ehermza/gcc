#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

char *srt_to_sub(Srt prfo) {
//	char *inter="02:37:28,500 --> 02:37:33,257";
	char *inter= prfo.intervalo;
	inter[ 8]= '.';
	inter[25]= '.';
	char *tiempo= malloc(sizeof(char)*FRAG);

	strncpy(tiempo, inter, 12);
	long frame_uno= get_frame(tiempo);

	inter+= 17;
	strncpy(tiempo, inter, 12);
	long frame_dos= get_frame(tiempo);

	char *prim_frase= prfo.frase_uno;
	char *sgda_frase= prfo.frase_dos;	
	char *oracion= malloc(sizeof(char)*ORAC);

	if (strlen(prfo.frase_dos) > 0)
	{
		sprintf(oracion, "{%d}{%d}%s|%s\r\n", frame_uno, 
			frame_dos, prim_frase, sgda_frase);
	} else {
		sprintf(oracion, "{%d}{%d}%s\r\n", frame_uno, 
			frame_dos, prim_frase);
	}
	return oracion;
}

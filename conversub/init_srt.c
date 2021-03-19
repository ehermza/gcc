
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "funciones.h"

void resolver_srt()
{
	int paso= 0;
	char crter[0];	
	char *ptr_buf= buffer;
	int cont= read(fd_ent, buffer, SIZE);

	char *oracion= malloc(sizeof(char)*ORAC);
	char *temp= malloc(sizeof(char)*(FRAG+3));

	char *inter= malloc(sizeof(char)*FRAG);
	char *prim_frase= malloc(sizeof(char)*FRAG);
	char *sgda_frase= malloc(sizeof(char)*FRAG);

	Srt prfo;
	
	while (cont!= -1) 
	{
		strncpy(crter, ptr_buf, 1);
		ptr_buf++;
		if (*crter=='\0') break;

		if (*crter=='\r' && *ptr_buf=='\n') {	// SI HAY UN RETORNO..
			switch (paso) {
				case 0: break; //strcpy(number, temp); break;
				case 1: strcpy(inter, temp); break;
				case 2: strcpy(prim_frase, temp); break;
				case 3: strcpy(sgda_frase, temp); break;
			}
			memset(temp,'\0', FRAG);
			paso++;
			
			ptr_buf++;
			if (*ptr_buf==13 ) 
			{	// SI HAY 2 RETORNOS SEGUIDOS
				prfo.intervalo= inter;
				prfo.frase_uno= prim_frase;
				prfo.frase_dos= sgda_frase;

				oracion= srt_to_sub(prfo);

				write(fd_out, oracion, strlen(oracion));
				memset(sgda_frase,'\0', FRAG);
//				memset(sgda_frase,'\0', sizeof(sgda_frase));

				if (buffer +SIZE < ptr_buf +DANGER -200) {
					cont= rellenar_buf(ptr_buf);
					ptr_buf= buffer;
				}
				paso= 0;
				ptr_buf++;
			}
		} else strncat(temp, crter, 1);
	}
}

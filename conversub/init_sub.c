
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"

void resolver_sub()
{
	Sub prfo;
	char *oracion= malloc(sizeof(char)*ORAC);
	char *temp= malloc(sizeof(char)*(FRAG+3));
	char *prim_frase= malloc(sizeof(char)*FRAG);
	char *sgda_frase= malloc(sizeof(char)*FRAG);

	long frame_1, frame_2;
	char crter;
	int paso= 0, id= 1;

	char *ptr_buf= buffer;
	int cont= read(fd_ent, buffer, SIZE);

	while(cont!= -1) 
	{
		crter= *ptr_buf++;
		if (crter=='\0') break;
		
		if (crter!= 13 && paso < 4) {
			if ( paso < 2 )  {
				if (paso!= 0) { 
					ptr_buf++;
					frame_2= atol(ptr_buf);
				}
				else	frame_1= atol(ptr_buf);
	
				ptr_buf= index(ptr_buf, '}');
			}
			else if (paso==2 || paso==3) 
			{
				crter= *ptr_buf;
				while (crter!= '|' && crter!= 13) {
					strncat(temp, ptr_buf, 1);
					ptr_buf++;
					crter= *ptr_buf;
				}
				if (paso==2) strcpy(prim_frase, temp);
				if (paso==3) strcpy(sgda_frase, temp);
			}
			paso++;
			memset(temp,'\0', FRAG);
		} 
		else {
			prfo.numero= id++;
			prfo.frame_uno= frame_1;
			prfo.frame_dos= frame_2;
			prfo.frase_uno= prim_frase;
			prfo.frase_dos= sgda_frase;

			oracion= sub_to_srt(prfo);
			write(fd_out, oracion, strlen(oracion));
//			puts(oracion);
			memset(sgda_frase,'\0', FRAG);
			ptr_buf++;

			if (buffer +SIZE < ptr_buf +DANGER -200) {
				cont= rellenar_buf(ptr_buf);
				ptr_buf= buffer;
			}
			paso= 0;
		}
	}	
}

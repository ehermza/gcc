#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct estruct {
	int numero;
	char *intervalo;
	char *frase_uno;
	char *frase_dos;
} Parrafo;

int const DANGER= 1024;
int const SIZE= 10240; 
char buffer[10240];
char *ptr_buf= buffer;

int rellenar_buf(int fd_ent)
{
	// SI QUEDA POCO ESPACIO EN BUFFER..
//	char temp[DANGER];
	char *temp= malloc(sizeof(char)*DANGER);

	strcpy(temp, ptr_buf);			// COPIAR LO QUE RESTA VER A 'TEMP'
	memset(buffer,'\0', sizeof(buffer));	// BORRAR CONTENIDO 
	strcpy(buffer, temp);			// COPIAR 'TEMP' AL PRINCIPIO DE BUFFER
	free(temp);

	ptr_buf= buffer +strlen(buffer);	// COLOCAR PTR_BUF EN ULTIMO CRTER 
	int sin_usar= buffer+ SIZE- ptr_buf;	// CALCULAR ESPACIO Q SOBRA 
	int cont= read(fd_ent, ptr_buf, sin_usar);	// COPIAR EN ESE ESPACIO LO NUEVO DE FD
		
	return cont;
}

int main()
{
	int fd_ent;
	if ((fd_ent= open("face.srt", O_RDONLY))==-1) return 1;
	int cont= read(fd_ent, buffer, SIZE);

	int paso=0;

	Parrafo *prfo;
	char *oracion= malloc(sizeof(char)*70);
	char *inter= malloc(sizeof(char)*36);
	char *prim_frase= malloc(sizeof(char)*64);
	char *sgda_frase= malloc(sizeof(char)*64);
	
	while (cont!=-1) 
	{
		char crter[0];
		strncpy(crter, ptr_buf, 1);
		ptr_buf++;
		if (*crter=='\0') break;

		if (*crter==13 && *ptr_buf==10 ) {	// SI HAY UN RETORNO..
			switch (paso) {
				case 0: break; //strcpy(number, oracion); break;
				case 1: strcpy(inter, oracion); break;
				case 2: strcpy(prim_frase, oracion); break;
				case 3: strcpy(sgda_frase, oracion); break;
			}
			memset(oracion,'\0', sizeof(oracion));
			paso++;
			
			ptr_buf++;
			if (*ptr_buf==13 ) 
			{	// SI HAY 2 RETORNOS SEGUIDOS
				puts(inter);
				prfo->intervalo= inter;
				prfo->frase_uno= prim_frase;
				prfo->frase_dos= sgda_frase;
//				convertir_srt(prfo);

				memset(sgda_frase,'\0', sizeof(sgda_frase));
				paso= 0;
				ptr_buf++;

				if (buffer +SIZE < ptr_buf +DANGER -200) 
				{
					cont= rellenar_buf(fd_ent);
					ptr_buf= buffer;
				}
			}
		} else strncat(oracion, crter, 1);
	}
	close(fd_ent);
	return 0;
}

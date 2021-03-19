#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int rellenar_buf(char *ptr_buf)
{
	// SI QUEDA POCO ESPACIO EN BUFFER..
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

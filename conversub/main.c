#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "funciones.h"
#define DIREC "./subtitles/"
#define FALLO 3

//	CONVERSUB Vers. 1.1
//	Autor: ezequielher -ezequielhernan@yahoo.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
int main(int argc, char *argv[])
{
	if (argc!= 7) 
	{
		fprintf(stderr, "\nModo ejecucion: %s -c veloc -i 'IN File' -o 'OUT File'\n", argv[0]);
		fprintf(stderr, "     ejemplo  : %s -c 23.976 -i peli.sub -o conver.txt\n", argv[0]);
		fprintf(stderr, "El archivo de entrada debe estar en directorio ./subtitle/\n");
		return 1;
	}

	int sgte; char *file; char *output;
	while((sgte= getopt(argc, argv, "c:i:o:"))!=-1)
	{
		switch (sgte) 
		{
			case 'c': fps= atof(optarg); break;
			case 'i': file= optarg; break;
			case 'o': output= optarg; break;
		}
	}	
	char *ent= malloc(sizeof(char)*64);
	strcpy(ent, DIREC); strcat(ent, file);

	char *sal= malloc(sizeof(char)*64);
	strcpy(sal, DIREC); strcat(sal, output); 

	char *extens= rindex(ent, '.');
	if ((fd_ent= open(ent, O_RDONLY))==-1) return fd_ent;
	if ((fd_out= open(sal, O_CREAT | O_WRONLY, 0666))==-1)  return fd_ent;

	if (!strcmp (extens,".srt")) 
		resolver_srt();

	else if (!strcmp (extens,".sub"))
		resolver_sub();

	else 
		fprintf(stderr, "Formato %s: no es un archivo de subtitulo\n", extens);

	close(fd_out);
	close(fd_ent);

	return 0;
}

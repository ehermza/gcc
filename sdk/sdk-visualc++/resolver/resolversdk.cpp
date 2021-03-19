
/****************************************************************************************
	Programa: SUDOKU		*	Author: ezequielher		*	version 1: 31/03/2010		*
/****************************************************************************************
el algoritmo se basa en ir llenando una matriz de 9×9 desde la esquina superior			*
izquierda comenzando por el número más chico posible, hasta llegar algun casillero		*
donde NO exista un valor coherente. En tal caso se retrocede un casillero para			*
incrementar su valor en +1 (o más) y asignar al casillero sgte el valor más chico posible.
Mostrará la 1ra solución encontrada, en caso de no existir avisará al usuario.			*
   Visitar Sitio web: http://ezequielher.wordpress.com/									*
*****************************************************************************************/

#include <stdio.h>
#include <string.h>

#define CONTINUAR 3
#define RETROCEDE 15


int matrizSudok[9][9];			// matriz ppal. que luego se imprime una vez resuelta 
int matrizSudokVert[9][9];		// cada fila representa una columna del sudoku
int matrizSudokCuad[9][9];		// cada fila representa un cuadro del sudoku

int matrizIngresada[9][9];		// se llenará dinámicamente accediendo al archivo .txt

int totalSolucion;

bool getDataFile()
{
	/*
	Para llenar matrizIngresada[][] se requiere del archivo 'prueba.txt' 
	getDataFile()= true al haber recogido 9 filas con 9 valores para cada fila.*/

 	FILE *archivo;
 
 	char crteres[100];
 
 	archivo = fopen("prueba.txt","r");
 
 	if (archivo == NULL) {
		printf("Error al intentar abrir archivo .txt\n");
		return false;
	}
	int ctrlX=0, ctrlY=0;
 
 	while (!feof(archivo))
 	{
 		fgets(crteres,100,archivo);

		int fsize= strlen(crteres);
		int ptr=0, nroxfila=0;
		while(fsize>= ptr) 
		{
			char ch= crteres[ptr++];
			if(ch>='0'&& ch<='9') {
				//printf("%d,%d,%d\n",ctrlX,ctrlY,ch-'0');
				matrizIngresada[ctrlY][ctrlX++]= ch-'0';	
				nroxfila++;
			}
		}
		ctrlX= 0;
		if(nroxfila==9) {
		//if(nroxfila!=9) return false;
			ctrlY++;
		} else if(nroxfila!= 0)
			return false;
 	}

	return true;

}
void printMatriz()
{
	/* 
	Esta funcion imprime estado actual de la matriz 'matrizSudok' */
	printf("-----+------+------+\n");
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			printf("%d|", matrizSudok[X][Y]);
			if(X%3==2)printf(" ");
		}
		printf("\n");
		if(Y%3==2)printf("\n");
	}

}

void setValorToMatrices(int x, int y, int VALOR)
{
	//printf("x:%d,y:%d,r:%d",x,y,VALOR);
	matrizSudok[x][y]= VALOR;

	int posXvert= y;
	int posYvert= x;
	matrizSudokVert[posXvert][posYvert]= VALOR;

	int posYcuad= int(y/3)*3 + int(x/3);
	int posXcuad= (y%3)*3 + (x%3);
	matrizSudokCuad[posXcuad][posYcuad]= VALOR;
}

void setPistasToMatriz()
{
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			int tl= matrizIngresada[X][Y];
			if(tl>0 && tl<=9)
				setValorToMatrices(Y,X,tl);
		}
	}
}

void vaciarMatrices() 
{
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			matrizSudok[X][Y]= 0;
			matrizSudokVert[X][Y]= 0;
			matrizSudokCuad[X][Y]= 0;
		}
	}
	//if(dejarPistas)setPistasToMatriz();
}


bool cumpleCondicion(int x, int y, int valor)
{
	//int CumpleCondicion= true;
	int t;
	int posYhoriz= y;
	for( t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas de la fila actual */
		if(valor== matrizSudok[t][posYhoriz])
			return false;
	}
	int posYcuad= int(y/3)*3 + int(x/3);
	for( t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas del cuadro actual */
		if(valor== matrizSudokCuad[t][posYcuad])
			return false;
	}
	//int posXvert= y;
	int posYvert= x;
	for( t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas de la columna actual*/
		if(valor== matrizSudokVert[t][posYvert])
			return false;
	}
	/* Si llegamos a esta instancia el valor no se repita */
	return true;
}
					
int Intentar(int X, int Y, int estado)
{		
	if(matrizIngresada[Y][X])	
		return estado;							
	/* 
	Si hay una pista en el casillero X,Y estara prohibido asignar un valor,*/

	int init= matrizSudok[X][Y]+ 1;
	//printf("%d\n", init);
	for(int Rt= init; Rt<10; Rt++ )
	{					
		//printf("X:%d,Y:%d,stat:%d\n",X,Y,Rt);
		if(cumpleCondicion(X,Y,Rt))
		{			
			setValorToMatrices(X,Y,Rt);
			if(!(X==7&& Y==8)) 
				return CONTINUAR;

			printMatriz();
			totalSolucion++;
			break;
		} 
	}
	setValorToMatrices(X,Y,0);
	return RETROCEDE;
}

void EncontrarSolucion() 
{
	int estadoActual= CONTINUAR;
	/*	estadoActual indica en quÉ sentido se deberá recorrer la matriz	
		como respuesta de intentar asignar un valor al casillero X,Y : 
	CONTINUAR, uno de los 9 posibles valores fue asignado y se puede avanzar un casillero.*/

	for(int Y=0; Y<9; Y++) 
	{		
		for(int X=0; X<9; X++) 
		{			
			/*	Se comienza a recorrer la matriz desde 0,0  
			de izquierda a derecha. de arriba hacia abajo. */
			estadoActual= Intentar(X,Y,estadoActual);

			if(estadoActual== RETROCEDE)
			{
			/*	RETROCEDE, no hay posibilidad de asignar valor al casillero actual
				Se retrocede de a 1 casillero hasta encontrar alguno 
				-	que no sea pista 
				-	su valor sea < 9 para incrementar su valor en +1.	*/
				Y= (!X? Y-1: Y);
				X= (!X? 7: X-2);
				
				if(Y<0)return;
			}				
		}
	}
	//return (estadoActual== CONTINUAR);
	
}
//printf("retrocede..X:%d,Y:%d \n",X,Y);

int main() 
{
	vaciarMatrices();
	if(!getDataFile())
	{
		printf("ARCHIVO MATRIZ CON DATOS INCORRECTOS!\n");
		return -1;
	}
	setPistasToMatriz();
	//printf("matriz inicial...\n");
	printMatriz();
	totalSolucion= 0;
	EncontrarSolucion();
	printf("total soluciones: %d\n", totalSolucion);
	//else printf("LO SIENTO, ESTE SUDOKU NO TIENE SOLUCION..\n ");


	return 1;
}

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

/*************************************************
	Generador y resolvedor de sudoku 1.0
	Author: ezequielher		Fecha: 20 abr-2010
	correo: ezequielhernan@yahoo.com
	************************************/
#define CONTINUAR 23
#define RETROCEDE 31
#define EXCEDE 15		/* estado que indica el sudoku actual tiene + de 1 solucion */

class clSudoku 
{
protected:
	int matrizSudok[9][9];			// matriz ppal. que luego se imprime una vez resuelta 
	int matrizSudokVert[9][9];		// cada fila representa una columna del sudoku
	int matrizSudokCuad[9][9];		// matrizSudokCuad[posic.dentro][nro.cuadro]
	/*	los 3 arreglos tienen valores en com˙n pero ubicados en lugares distintos	
		matrizSudok[1][7]= matrizSudokVert[7][1]= matrizSudokCuad[3][6]	*/		
public:
	clSudoku() 
	{
	}

	int getValor(int x, int y) 
	{
		return this->matrizSudok[x][y];
	}
	void vaciarMatrices() ;	
	void setValorToMatrices(int x, int y, int VALOR);
	bool cumpleCondicion(int x, int y, int valor);
	bool GenerarSdk() ;
	void Mostrar() ;

};

class clIncompl: public clSudoku {
	private:
		int totalSolucion;
		int totalPistas;
		int matrizIngresada[9][9];

	public:
		clIncompl() {
			for (int Y=0;Y<9;Y++) {	
				for (int X=0;X<9;X++) {
					this->matrizIngresada[X][Y]= 0;
				}
			}
		}
		void Mostrar() ;	
		void setPistaXCuadro(clSudoku sdk) ;
		void setPistaAleat(clSudoku sdk);
		int Intentar(int X, int Y, int estado);
		int Resolver();	/** devuelve cant de posibles resultados, si la matriz tiene 
							m·s de una soluciÛn la fc. devolver· 2 SIEMPRE	**/		
		void setPistasToMatriz();
		int getCantPistas() { return this->totalPistas; }
};

void clSudoku:: vaciarMatrices() 
{
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			this->matrizSudok[X][Y]= 0;
			this->matrizSudokVert[X][Y]= 0;
			this->matrizSudokCuad[X][Y]= 0;
			//this->matrizIngresada[X][Y]= 0;
		}
	}
}

void clSudoku:: setValorToMatrices(int x, int y, int VALOR)
{
	//printf("x:%d,y:%d,r:%d",x,y,VALOR);
	this->matrizSudok[x][y]= VALOR;

	int posXvert= y;
	int posYvert= x;
	this->matrizSudokVert[posXvert][posYvert]= VALOR;

	int posYcuad= int(y/3)*3 + int(x/3);
	int posXcuad= (y%3)*3 + (x%3);
	this->matrizSudokCuad[posXcuad][posYcuad]= VALOR;
}
bool clSudoku:: cumpleCondicion(int x, int y, int valor)
{
	//int CumpleCondicion= true;
	int t;
	int posYhoriz= y;
	for(t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas de la fila actual */
		if(valor== this->matrizSudok[t][posYhoriz])
			return false;
	}
	int posYcuad= int(y/3)*3 + int(x/3);
	for( t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas del cuadro actual */
		if(valor== this->matrizSudokCuad[t][posYcuad])
			return false;
	}
	//int posXvert= y;
	int posYvert= x;
	for( t=0; t<9; t++) 
	{
		/*	Verificar si el valor 'valor' no se encuentra en ninguna 
		de las casillas de la columna actual*/
		if(valor== this->matrizSudokVert[t][posYvert])
			return false;
	}
	/* Si llegamos a esta instancia el valor no se repita */
	return true;
}
bool clSudoku:: GenerarSdk() 
{	/**********************************
	producir una secuencia de valores p matriz[][] de modo 
	que cumpla con todas las reglas del sudoku 
	***********************************/
	int falloFila= 0;

	for (int Y=0;Y<9;Y++) 
	{		
		int repet= 0;			
		for (int X=0; X<9; X++) 
		{	
			int valor= rand()% 9+ 1;
			if(cumpleCondicion(X,Y,valor)) {
				/* Parece que la nueva cifra encaja bien.*/
				setValorToMatrices(X,Y,valor);
				repet= 0;
			}
			else { 
				if(repet== 30) {	
					for (int Xy=0; Xy<9; Xy++) 
					{	/* intentamos con todos los valores posibles
						pero ninguno puede ser asignado: limpiar fila completa */
						setValorToMatrices(Xy,Y,0);
					}	
					X=-1;	// volver 1ra pocicion del array actual
					repet= 0;
					if(++falloFila==50)
						return false;
				} else { 
					X-=1; repet+=1;
				}	// probaremos con otro valor aleatorio;
			}
		}
	}
	return true;
	
};
void clSudoku:: Mostrar() 
{
	cout << "\n\nSOLUCION\n-----+------+------+" << endl;
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			cout << this->matrizSudok[X][Y] << "|";
			if(X%3==2)cout << " ";
		}
		cout << endl;
		if(Y%3==2)cout << endl;
	}
	
}

void clIncompl:: Mostrar() 
{
	cout << "\nSIN RESOLVER pistas:" << this->totalPistas;
	cout << "\n-----+------+------+" << endl;
	for (int Y=0;Y<9;Y++) 
	{		
		for (int X=0;X<9;X++) 
		{
			cout << this->matrizSudok[X][Y] << "|";
			if(X%3==2)cout << " ";
		}
		cout << endl;
		if(Y%3==2)cout << endl;
	}
	
}
void clIncompl:: setPistaXCuadro(clSudoku sdk) 
{
/**********************************************************
	Asignar un valor p cada cuadro de matriz 'this' en posiciones aleatorias y 
	asignando los valores contenidos en matriz 'sdk'.
	total de asignaciones = 9	
 ******************************/	//vaciarMatrices();
	//srand((unsigned)time(NULL)); 
	for (int Cuadro=0;Cuadro<9;Cuadro++) 
	{		
		int Cx= rand()% 9;
		int xnormal= (Cuadro%3)*3+ (Cx%3);
		int ynormal= int(Cuadro/3)*3+ int(Cx/3);	
		//printf("%d, %d\n", xnormal, ynormal);
		int valor= 	sdk.getValor(xnormal, ynormal);
		matrizIngresada[ynormal][xnormal]= valor;
		//setValorToMatrices(xnormal, ynormal, valor);
	}
	this->totalPistas= 9;
	//setPistasToMatriz();
}
void clIncompl:: setPistaAleat(clSudoku sdk) 
{
/*	Asignar solo 1 valor de la matriz sdk en cualquier posicion vacia (random) 
	de matriz 'this' asignando los valores contenidos en matriz 'sdk'.*/
	int Px, Py, vlr= 'f';
	while(vlr!= 0||Px*Py==64) 
	{
		Px= rand()% 9;
		Py= rand()% 9;
		vlr= matrizIngresada[Py][Px];
		//printf("%d\n",vlr);
	}
	int t= sdk.getValor(Px, Py);
	matrizIngresada[Py][Px]= t;
	cout << "X:" << Px << ",Y:" << Py << "= " << t ;
	this->totalPistas++;
}
int clIncompl:: Intentar(int X, int Y, int estado)
{		
	/*************************
		Intenta colocar valores de(1,9) en casilla X,Y hasta alguna encaje bien.
	*************************************************/
	if(matrizIngresada[Y][X])	
		return estado;							
	/*	Si hay una pista en el casillero X,Y estara prohibido asignar un valor,*/

	int init= matrizSudok[X][Y]+ 1;
	//printf("%d\n", init);
	for(int Rt= init; Rt<10; Rt++)
	{					
		//printf("X:%d,Y:%d,stat:%d\n",X,Y,Rt);
		if(cumpleCondicion(X,Y,Rt))
		{			
			setValorToMatrices(X,Y,Rt);
			if(!(X==8&& Y==8)) 
				return CONTINUAR;
			/*	si se resolvio la matriz se evalua cant de soluciones encontradas
				si fueron m·s de 1 se detiene proceso p aÒadir otra pista */
			if(this->totalSolucion++)
				return EXCEDE;
			break;
		} 
	}
	setValorToMatrices(X,Y,0);
	return RETROCEDE;
}

int clIncompl::Resolver()
{
	this->totalSolucion= 0;
	int estadoActual= CONTINUAR;

/*	estadoActual indica en qu… sentido se deber· recorrer la matriz	
	como respuesta de intentar asignar un valor al casillero X,Y : 
	CONTINUAR, uno de los 9 posibles valores fue asignado y se puede avanzar un casillero.
	RETROCEDE, no hay un valor que pueda asignarse a X,Y: retroceder 1 casillero	*/
	vaciarMatrices();
	setPistasToMatriz();

	for(int Y=0; Y<9; Y++) 
	{		
		for(int X=0; X<9; X++) 
		{	/*	Se comienza a recorrer la matriz desde 0,0  
			de izq a der. de arriba a abajo. */
			estadoActual= Intentar(X,Y,estadoActual);
		
			if(estadoActual==RETROCEDE)
			{	/*	RETROCEDE, no hay posibilidad de asignar valor al casillero actual
				Se retrocede de a 1 casillero hasta encontrar alguno 
				-	que no sea pista 
				-	su valor sea < 9 para incrementar su valor en +1.	*/
				Y= (!X? Y-1: Y);
				X= (!X? 7: X-2);
				
				if(Y< 0) { return this->totalSolucion; }
			}	
			else if(estadoActual==EXCEDE) 
				return this->totalSolucion; 
		}
	}
	cout << ".. final de matriz" << endl;
	return NULL;
	//return (estadoActual== CONTINUAR);			
}

void clIncompl::setPistasToMatriz()
{
	for (int Y=0;Y<9;Y++) {		
		for (int X=0;X<9;X++) {
			int tl= matrizIngresada[X][Y];
			if(tl>0 && tl<=9)
				setValorToMatrices(Y,X,tl);
		}
	}
}
int Aplicacion() 
{
	clSudoku sdkCompl;
	clIncompl sdkPistas;

	bool exito= false;	
	while(!exito)
	{
		sdkCompl.vaciarMatrices();
		exito= sdkCompl.GenerarSdk();
		cout << "\\nueva matriz..probando\n";
		/* Se generan sudokus con valores aleat hasta obtener
			alguno completo que cumpla con todas las reglas	*/
	}
	cout << "\\matriz encontrada\n";
	sdkPistas.setPistaXCuadro(sdkCompl);

	int slc= 'i';	
	while(slc!= 1 && slc!=NULL)
	{
		cout << ": + de 1 solucion\n";
		sdkPistas.setPistaAleat(sdkCompl);
		//sdkPistas.Mostrar();
		//getchar();
		slc= sdkPistas.Resolver();
	}
	if(slc==NULL)return 't';

	sdkCompl.Mostrar();
	sdkPistas.Mostrar();
	 
	return sdkPistas.getCantPistas();
	//sdkPistas.dltRedundancia();

}
int main() 
{
	int npistas= 't';
	srand((unsigned)time(NULL)); 

	while (npistas > 35)
	{
		npistas= Aplicacion();
	}
	getch();
	return 0;
}
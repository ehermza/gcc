reinas: add_closed.o add_open.o reset_amen.o es_objetivo.o ver_tablero.o set_amen.o cas_libres.o mostrar_resp.o contar_hijos.o sgte_nodo.o main.o funciones.h
	gcc add_closed.o add_open.o reset_amen.o es_objetivo.o ver_tablero.o set_amen.o cas_libres.o mostrar_resp.o contar_hijos.o sgte_nodo.o main.o funciones.h -o reinas

add_closed.o:	add_closed.c	funciones.h
		gcc -c add_closed.c
add_open.o:	add_open.c 	funciones.h
		gcc -c add_open.c
reset_amen.o:	reset_amen.c	funciones.h
		gcc -c reset_amen.c
es_objetivo.o:	es_objetivo.c	funciones.h
		gcc -c es_objetivo.c
ver_tablero.o:	ver_tablero.c	funciones.h
		gcc -c ver_tablero.c
set_amen.o:	set_amen.c	funciones.h
		gcc -c set_amen.c
cas_libres.o:	cas_libres.c 	funciones.h
		gcc -c cas_libres.c
mostrar_resp.o:	mostrar_resp.c	funciones.h
		gcc -c mostrar_resp.c
contar_hijos.o:	contar_hijos.c 	funciones.h
		gcc -c contar_hijos.c
sgte_nodo.o:	sgte_nodo.c 	funciones.h
		gcc -c sgte_nodo.c
main.o:		main.c	funciones.h
		gcc -c main.c

clean:
	rm *.o reinas;

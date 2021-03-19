	
	Programa: CONVERSUB Vers.1.1

	CONVERSOR ARCHIVOS DE SUBTITULOS PARA PELICULAS
	TRANSFORMA FORMATOS SRT to SUB Y VICEVERSA
 	 Terminado: 29-04-08
	Modificado: 08-05-08 (vers. 1.1)

	Autor: ezequielher (Ezequiel Hernandez)
	E-mail: ezequielhernan@yahoo.com 
	http://ezequielher.wordpress.com
	
IMPORTANTE: ES OBLIGATORIO QUE LOS ARCHIVOS DE SUBTITULOS QUE QUIERAS
	CONVERTIR SE COLOQUEN DENTRO DE LA CARPETA ./subtitles/

prompt\> ./convertir -c 'fps' -i 'archivo'

prompt\> ./convertir -c 25 -i scarface.sub
prompt\> ./convertir -c 23.97 -i titanic.srt

Si el archivo de entrada es de formato SUB la conversion 
se hara' al formato opuesto SRT sin necesidad de especificarlo
Pasa lo mismo en el caso opuesto.

ARGUMENTOS REQUERIDOS PARA LA EJECUCION

	'fps': 	frames por segundos.

	'archivo': Archivo de subtitulo con formato 'sub' o 'srt'
		que se desea convertir. Este archivo es de entrada 
		y nunca sera' modificado por esta aplicacion.

SALIDA:	
	'CONVERSUB' siempre genera un archivo de texto plano.
	Tendra' el nombre del archivo completo + '.txt' y se
	encontrara dentro de la carpeta ./subtitles/



#include <unistd.h>	// Para funciones read & write
#define SIZE 10240
#define DANGER 1024
#define ORAC 256
#define FRAG 64

typedef struct estruct {
	char *intervalo;
	char *frase_uno;
	char *frase_dos;
} Srt;

typedef struct conseg {
	int numero;
	long frame_uno;
	long frame_dos;
	char *frase_uno;
	char *frase_dos;
} Sub;

int fd_out;
int fd_ent;
float fps;	//frames por seg.
char buffer[SIZE];

void resolver_srt();
char *srt_to_sub(Srt prfo);
long get_frames(char *tiempo);

void resolver_sub();
char *sub_to_srt(Sub prfo);
char *get_tiempo(long frames);

int rellenar_buf(char *ptr_buf);

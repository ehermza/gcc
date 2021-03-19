LDLIBS=
CFLAGS=-g -Wall
TARGETS=conversub

conversub:	rellenar.o init_srt.o to_sub.o get_frames.o init_sub.o to_srt.o get_tiempo.o main.o funciones.h
		$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
clean:
		rm -f *.o $(TARGETS)


CFLAGS = -Wall -std=c99 -g # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
    objects = beale.o libcifras.o libfila.o libcodificar.o libfile.o libdecodificar.o

all: beale.o libcifras.o libfila.o libcodificar.o libfile.o libdecodificar.o
	$(CC) -o beale beale.o libcifras.o libfila.o libcodificar.o libfile.o libdecodificar.o $(LDFLAGS)

libcifras.o: libcifras.c
	$(CC) -c $(CFLAGS) libcifras.c

libfila.o: libfila.c
	$(CC) -c $(CFLAGS) libfila.c

libcodificar.o: libcodificar.c
	$(CC) -c $(CFLAGS) libcodificar.c

libdecodificar.o: libdecodificar.c
	$(CC) -c $(CFLAGS) libdecodificar.c

beale.o: beale.c
	$(CC) -c $(CFLAGS) beale.c

libfile.o: libfile.c
	$(CC) -c $(CFLAGS) libfile.c

clean:
	rm -f $(objects) *~

purge: clean
	rm -f beale


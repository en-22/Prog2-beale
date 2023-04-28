# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -std=c99 -g # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
    objects = beale.o cifras.o libfila.o codificar.o file.o decodificar.o

beale: beale.o cifras.o libfila.o codificar.o file.o decodificar.o
	$(CC) -o beale beale.o cifras.o libfila.o codificar.o file.o decodificar.o $(LDFLAGS)

cifras.o: cifras.c
	$(CC) -c $(CFLAGS) cifras.c

libfila.o: libfila.c
	$(CC) -c $(CFLAGS) libfila.c

codificar.o: codificar.c
	$(CC) -c $(CFLAGS) codificar.c

decodificar.o: decodificar.c
	$(CC) -c $(CFLAGS) decodificar.c

beale.o: beale.c
	$(CC) -c $(CFLAGS) beale.c

file.o: file.c
	$(CC) -c $(CFLAGS) file.c

clean:
	rm -f $(objects) teste

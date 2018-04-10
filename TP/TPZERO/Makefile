# MakeFile do TP0 de AEDS III
# Vinicius Antonio Soares Ferreira - 2013031275
CC = gcc
CFLAGS = -c -Wall
all: tp0
tp0: main.o grafo2.o musica.o
	$(CC) main.o grafo2.o musica.o -o tp0
main.o: main.c 
	$(CC) $(CFLAGS) main.c

grafo2.o: grafo2.c grafo2.h
	$(CC) $(CFLAGS) grafo2.c

musica.o: musica.c musica.h
	$(CC) $(CFLAGS) musica.c

clean:
	rm -rf *o tp0
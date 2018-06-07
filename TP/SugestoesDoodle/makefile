# MakeFile do TP2 de AEDS III
# Vinicius Antonio Soares Ferreira - 2013031275
CC = gcc
CFLAGS = -c -Wall
all: tp2
tp2: main.o lvnsh.o
	$(CC) main.o lvnsh.o -o tp2
main.o: main.c 
	$(CC) $(CFLAGS) main.c

lvnsh.o: lvnsh.c lvnsh.h
	$(CC) $(CFLAGS) lvnsh.c

clean:
	rm -rf *o tp2
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _MUSICA_H
#define _MUSICA_H

typedef struct pessoa{ // estrutura da informação de uma pessoa
    int idade, visitado;
}pessoa_obj, *pessoa_pont;

void createPessoa(pessoa_pont lista, int id, int age); // seta os valores da pessoa relacionada

pessoa_pont createEmptyList(int n); // cria-se a lista com tamanho n vazia

// void addOnList(pessoa_pont list, int id, int age);

void Visited(pessoa_pont person, int id); // muda o valor de visita

void destroyList(pessoa_pont lista); // desaloca a memoria da lista

void printList(pessoa_pont lista, int tam); // printa todos os valores da lista

#endif
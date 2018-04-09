#include "grafo2.h"

#ifndef _MUSICA_H
#define _MUSICA_H

typedef struct pessoa{
    int idade, visitado;
}pessoa_obj, *pessoa_pont, **pessoa_list;

void createPessoa(pessoa_pont lista, int id, int age);

pessoa_pont createEmptyList(int n);

// void addOnList(pessoa_pont list, int id, int age);

void Visited(pessoa_pont list, int id);

void destroyList(pessoa_pont list);

#endif
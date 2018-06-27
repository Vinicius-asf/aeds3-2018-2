#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "grafo2.h"

#ifndef _HEUR_H
#define _HEUR_H

typedef struct rodada{ // estrutura da informação de uma pessoa
    int n_rodada, visitado;
}rodada, *rodada_pont;

rodada_pont createEmptyRounds(int n);

void createRound(pessoa_pont rounds);

void Visited(rodada_pont round, int id);

void destroyRounds(rodada_pont rounds);

void printRounds(rodada_pont rounds);

int findRounds(graphL_pont grafo);

#endif
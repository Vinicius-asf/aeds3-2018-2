#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>                       //para uso da função calloc

typedef struct modlista {
        int id;
        int valor;
        struct modlista *prox;           //ponteiro para o proximo elemento
}**vetor, lista, *elo;                 //um ponteiro duplo de vetor, a estrutura e o ponteiro para a struct


void inicializevetor(vetor v, int pvalor, int index);

void createElo(vetor v, int pindex, int nindex, int nvalor);

int getValor(vetor v, int index);

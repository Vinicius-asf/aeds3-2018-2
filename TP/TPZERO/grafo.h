#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>                       //para uso da função calloc

typedef struct modlista {
        int id;
        int valor;
        struct modlista *prox;           //ponteiro para o proximo elemento
}**vetor, lista, *elo;                 //um vetor de ponteiro para a struct, a estrutura, ponteiro para a struct



void inicializevetor(vetor v, int pvalor, int index){
        elo nucleo;
        nucleo->prox=NULL;
        nucleo->id=index;
        nucleo->valor=pvalor;
        v[index] = nucleo;
}

void createElo(vetor v, int pindex, int nindex, int nvalor){
        elo novo, aux;
        aux=v[pindex];
        while(aux->prox!=NULL){
                aux=aux->prox;
        }
        aux->prox=novo;
        aux=v[novo->id];
        while(aux->prox!=NULL){
                aux=aux->prox;
        }
        aux->prox=v[pindex];
        
}


#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>                       //para uso da função calloc

#include"grafo.h"

void inicializevetor(vetor v, int index, int valornucleo){
        elo nucleo;

        nucleo->prox=NULL;
        nucleo->id=index;
        nucleo->valor=valornucleo;
        v[index] = nucleo;
}

void createElo(vetor v /* vetor onde o elo sera inserido */, int pindex /* qual lista que tera o elo inserido */, int nindex /* id do novo elo */ , int nvalor /* valor do novo elo */){
        elo novo, aux;
        aux=v[pindex];
        while(aux->prox!=NULL){
                aux=aux->prox;
        }
        aux->prox=novo;
        aux=v[novo->id]; // certificar que esse vetor existe por meio do inicializevetor em um loop
        while(aux->prox!=NULL){
                aux=aux->prox;
        }
        aux->prox=v[pindex];
        
}

int getValor(vetor v, int index){
    return v[index]->valor;
}


#include "musica.h"

pessoa_pont createEmptyList(int n){
    pessoa_pont list;
    list = (pessoa_pont)malloc(n*sizeof(pessoa_obj));
    return list;
}

void createPessoa(pessoa_pont lista, int id, int age){
    (lista+id)->idade=age;
    (lista+id)->visitado=0;
}

void Visited(pessoa_pont list, int id){
    (list+id)->visitado=1;
}

void destroyList(pessoa_pont list){
    free(list);
}


/* pessoa_pont createPessoa(int id, int age){
    pessoa_pont novaPessoa = (pessoa_pont)malloc(sizeof(pessoa_obj));
    novaPessoa->noh->vertice = id;
    novaPessoa->idade = age;
    novaPessoa->visitado = 0;
    novaPessoa->noh->prox = NULL;
    return novaPessoa;
} */

// void addIdade2List (listidades_pont lista);
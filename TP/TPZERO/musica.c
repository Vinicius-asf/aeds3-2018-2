#include "musica.h"

pessoa_pont createEmptyList(int n){
    pessoa_pont list;
    list = (pessoa_pont)malloc(n*sizeof(pessoa_obj)); // cria a lista com tamanho n
    return list;                                      //  alocando espaço para a estrutura de uma pessoa
}

void createPessoa(pessoa_pont lista, int id, int age){ // seta os valores corretos de uma pessoa na lista
    (lista+id)->idade=age;
    (lista+id)->visitado=0;
}

void Visited(pessoa_pont person, int id){
    (person+id)->visitado=1; // muda o valor de controle visitado
}

void destroyList(pessoa_pont list){
    free(list); // desaloca a memoria da lista
}

void printList(pessoa_pont lista, int tam){ // printa todos os valores armazeados na lista
    int i;
    printf("\nLista de pessoas:\n");
    for (i=0; i<tam; i++){
        printf("%d:%d|%d ",i , (lista+i)->idade, (lista+i)->visitado);
    }
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
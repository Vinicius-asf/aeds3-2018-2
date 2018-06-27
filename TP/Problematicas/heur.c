#include "heur.h"

rodada_pont createEmptyRounds(int n){
    rodada_pont rounds;
    rounds = (rodada_pont)malloc(n*sizeof(rodada)); // cria a lista com tamanho n
    return rounds;                                      //  alocando espaço para a estrutura de uma pessoa
}

void createRound(rodada_pont rounds, int id){ // seta os valores corretos de uma pessoa na lista
    (rounds+id)->idade=0;
    (rounds+id)->visitado=0;
}

void Visited(rodada_pont rounds, int id){
    (rounds+id)->visitado=1; // muda o valor de controle visitado
}

void destroyList(rodada_pont rounds){
    free(rounds); // desaloca a memoria da lista
}

void printList(rodada_pont rounds, int tam){ // printa todos os valores armazeados na lista
    int i;
    printf("\nLista de rodadas por noh:\n");
    for (i=0; i<tam; i++){
        printf("%d:%d|%d ",i , (rounds+i)->n_rodada, (rounds+i)->visitado);
    }
}

int findRounds(graphL_pont grafo, rodada_pont l_rodadas){
    int rounds = 0;
    int i = 0, j = 0;
    int j = 'a';
}
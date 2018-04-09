#include "musica.h"
#include "grafo2.h"

int main (){
    int i = 3;
    pessoa_pont lista = createEmptyList(i);
    createPessoa(lista,0,10);
    createPessoa(lista,2,20);
    createPessoa(lista,1,15);
    
    for (i=0; i<3; i++){
        printf("%d|%d ",lista[i].idade,lista[i].visitado);
    }

    Visited(lista, 1);

    for (i=0; i<3; i++){
        printf("%d|%d ",lista[i].idade,lista[i].visitado);
    }

    destroyList(lista);
    
    
    /* graphL_pont grafo = createGraphL(3);
    addAresta(grafo,0,1);
    addAresta(grafo,0,2);
    addAresta(grafo,1,2);
    printGraphL(grafo);
    destroyGraphL(grafo); */
    return 0;
}
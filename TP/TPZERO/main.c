#include "grafo2.h"

int main (){
    graphL_pont grafo = createGraphL(3);
    addAresta(grafo,0,1);
    addAresta(grafo,0,2);
    addAresta(grafo,1,2);
    printGraphL(grafo);
    destroyGraphL(grafo);  
    return 0;
}
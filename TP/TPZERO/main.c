#include "musica.h"
#include "grafo2.h"

void visitingPerson(pessoa_pont lista, graphL_pont grafo, int id, int* contador){ // função que percorre o grafo
    if(lista[id].visitado==0){ // caso a pessoa ja escutou a musica, ela é ignorada
        Visited(lista, id);
        if(lista[id].idade<35){ // caso a pessoa seja menor de 35 anos, ela recomenda a musica
            *contador+=1;       // ou seja, passa essa função para os outros nós com quem esta ligada
            listadj_noh_pont auxnoh = grafo->arrayList[id].header; // aponta para o cabeçaria da lista de relações da pessoa referenciada
            while(auxnoh){
                visitingPerson(lista,grafo,auxnoh->vertice,contador);
                auxnoh = auxnoh->prox;
            }
        }
    }
}

int main (){
    int i = 0;
    int age = 0;
    int id = 0;
    int pessoa = 0, relacao = 0;
    scanf("%d%d",&pessoa,&relacao);

    pessoa_pont list = createEmptyList(pessoa);
    graphL_pont grafo = createGraphL(pessoa);
    
    for(i = 0; i<pessoa; i++){
        scanf("%d%d",&id,&age);
        createPessoa(list, id-1, age);
    }

    //printList(list, pessoa);

    for(i = 0; i<relacao; i++){
        scanf("%d%d",&id,&age);
        addAresta(grafo, id-1, age-1);
    }

    //printGraphL(grafo);
    scanf("%d",&id);
    i = 0;
    visitingPerson(list,grafo/*, grafo->arrayList[id] */,id-1,&i);

    printf("%d\n",i);
    //printList(list, pessoa);
    
    destroyList(list);
    destroyGraphL(grafo);
    return 0;
}
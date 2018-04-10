#include "musica.h"
#include "grafo2.h"

void visitingPerson(pessoa_pont lista, graphL_pont grafo/* , listadj_obj gflista */, int id, int* contador){
    if(lista[id].visitado==0){
        Visited(lista, id);
        if(lista[id].idade<35){
            *contador+=1;
            //int i;
            listadj_noh_pont auxnoh = grafo->arrayList[id].header;
            while(auxnoh){
                visitingPerson(lista,grafo,auxnoh->vertice,contador);
                auxnoh = auxnoh->prox;
            }
            /* for(i = 0; i<grafo->arrayList[id].nmembros; i++){
                visitingPerson(lista,grafo,auxnoh->vertice,contador);
                auxnoh = auxnoh->prox;
            } */   
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

    printf("\nTotal:%d",i);
    //printList(list, pessoa);
    
    destroyList(list);
    destroyGraphL(grafo);
    return 0;
}
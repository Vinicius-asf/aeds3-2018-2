#include "grafo2.h"

listadj_noh_pont createNoh(int vert)
{
    listadj_noh_pont novoNoh = (listadj_noh_pont)malloc(sizeof(listadj_noh_obj));
    novoNoh->vertice=vert;
    novoNoh->prox= NULL;
    return novoNoh;
}

graphL_pont createGraphL(int nv){
    int i;
    graphL_pont graphL = (graphL_pont)malloc(sizeof(graphL_obj));
    graphL->nvertices = nv;

    graphL->arrayList = (listadj_pont)malloc(nv*sizeof(listadj_obj));
    for(i=0; i<nv; i++){
        graphL->arrayList[i].header=NULL;
        graphL->arrayList[i].nmembros=0;
    }
    return graphL;
}

void addAresta(graphL_pont graph, int source, int destination){
    listadj_noh_pont novoNoh = createNoh(destination);
    novoNoh->prox = graph->arrayList[source].header;
    graph->arrayList[source].header = novoNoh;
    graph->arrayList[source].nmembros++;
    ////////////////////////////////////
    novoNoh = createNoh(source);
    novoNoh->prox = graph->arrayList[destination].header;
    graph->arrayList[destination].header = novoNoh;
    graph->arrayList[destination].nmembros++;   
}

void printGraphL(graphL_pont graph){
    int i;
    for (i=0; i<graph->nvertices; i++){
        listadj_noh_pont auxpont = graph->arrayList[i].header;
        printf("\n%d: ",i);
        while(auxpont){
            printf("%d->",auxpont->vertice);
            auxpont = auxpont->prox;
        }
        printf("NULL");
    }
}

void destroyNoh(listadj_noh_pont noh){
    free(noh);
}

void destroyGraphL(graphL_pont graph){
    if(graph){
        if(graph->arrayList){
            int v;
            for(v=0;v < graph->nvertices; v++){
                listadj_noh_pont auxpont = graph->arrayList[v].header;
                while(auxpont){
                    listadj_noh_pont tmpo = auxpont;
                    auxpont = auxpont->prox;
                    destroyNoh(tmpo);
                }
            }
            free(graph->arrayList);
        }
        free(graph);
    }
}
#include "grafo2.h"

listadj_noh_pont createNoh(int vert)
{
    //alocação de memória de todo um nó, setando o valor de seu vértice e qual que o próximo noh é nulo
    listadj_noh_pont novoNoh = (listadj_noh_pont)malloc(sizeof(listadj_noh_obj));
    novoNoh->vertice=vert;
    novoNoh->prox= NULL;
    return novoNoh;
}

graphL_pont createGraphL(int nv){
    // criando o grafo, alocando a memoria para a tamanho dele
    int i=0;
    graphL_pont graphL = (graphL_pont)malloc(sizeof(graphL_obj));
    graphL->nvertices = nv;
    // criando as listas de relações de cada nó, considerando a quantidade de nós que esse grafo terá
    graphL->arrayList = (listadj_pont)malloc(nv*sizeof(listadj_obj));
    for(i=0; i<nv; i++){
        graphL->arrayList[i].header=NULL;
        graphL->arrayList[i].nmembros=0;
    }
    return graphL;
}

void addAresta(graphL_pont graph, int source, int destination){
    // cria o nó, seta o cabeçario da lista para o nó criado
    listadj_noh_pont novoNoh = createNoh(destination);
    novoNoh->prox = graph->arrayList[source].header;
    graph->arrayList[source].header = novoNoh;
    graph->arrayList[source].nmembros++;
    //////////////////////////////////// implentar uma condicional para suportar ambos tipos de grafos!
    // repete o processo para o outro nó - não direcionado
    novoNoh = createNoh(source);
    novoNoh->prox = graph->arrayList[destination].header;
    graph->arrayList[destination].header = novoNoh;
    graph->arrayList[destination].nmembros++;   
}

void printGraphL(graphL_pont graph){
    //printa todas as relações entre os nós
    printf("\nGrafo:");
    int i=0;
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
    free(noh); //desaloca a memoria do nó referenciado
}

void destroyGraphL(graphL_pont graph){
    //desaloca a memoria de todo o grafo
    if(graph){ // checa se o nó existe
        if(graph->arrayList){ // checa se a lista de relações existe
            int v=0;
            for(v=0;v < graph->nvertices; v++){ // loop para varrer cada lista de relações do grafo
                listadj_noh_pont auxpont = graph->arrayList[v].header;
                while(auxpont){ // esvazia a lista
                    listadj_noh_pont tmpo = auxpont;
                    auxpont = auxpont->prox;
                    destroyNoh(tmpo); // desaloca memorio do noh
                }
            }
            free(graph->arrayList); // depois que a lista esta vazia, desaloca a memoria dela
        }
        free(graph); // depois que o grafo esta vazio, desaloca a memoria dele
    }
}
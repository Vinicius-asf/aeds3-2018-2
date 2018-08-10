#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

typedef struct listadj_noh{ // estrutura do nó
    int vertice;
    struct listadj_noh *prox;
}listadj_noh_obj, *listadj_noh_pont;

typedef struct listadj{ // estrutura da lista de relações de um nó
    int nmembros;
    listadj_noh_obj *header;
}listadj_obj, *listadj_pont;

typedef struct graphL{ // estrutura de um grafo
    int nvertices;
    listadj_pont arrayList;
}graphL_obj, *graphL_pont;


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
    int i = 0;
    // cria o nó, seta o cabeçario da lista para o nó criado
    listadj_noh_pont novoNoh = createNoh(destination);
    if(graph->arrayList[source].header==NULL){
        novoNoh->prox = graph->arrayList[source].header;
        graph->arrayList[source].header = novoNoh;
    }
    else{
        listadj_noh_pont aux = graph->arrayList[source].header;
        for(i = 0;i <graph->arrayList[source].nmembros-1;i++){
            aux = aux->prox;
        }
        aux->prox=novoNoh;
    }
    graph->arrayList[source].nmembros++;
    //////////////////////////////////// implentar uma condicional para suportar ambos tipos de grafos!
    // repete o processo para o outro nó - não direcionado
    novoNoh = createNoh(source);
    if(graph->arrayList[destination].header==NULL){
        novoNoh->prox = graph->arrayList[destination].header;
        graph->arrayList[destination].header = novoNoh;
    }
    else{
        listadj_noh_pont aux = graph->arrayList[destination].header;
        for(i = 0; i< graph->arrayList[destination].nmembros-1; i++){
            aux = aux->prox;
        }
        aux->prox=novoNoh;
    }
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

void checkConex(graphL_pont grafo, int lista[], int* conec, int id){
    if(lista[id]==0){
        printf("%c,",id+97);
        lista[id]=1;
        *conec=1;
        listadj_noh_pont aux = grafo->arrayList[id].header;
        while(aux){
            checkConex(grafo,lista,conec,aux->vertice);
            aux = aux->prox;
        }
    }
}

int main(int argc, char const *argv[])
{
    int N = 0, V = 0, E = 0;
    int cases = 0;
    int con = 0;
    int result = 0;
    int visited[27];
    scanf("%d",&N);
    int i = 0;
    char A [10];
    for (cases = 0;cases<N;cases++){
        scanf("%d%d",&V,&E);
        con = 0;
        result = 0;
        graphL_pont grafo = createGraphL(V);
        for (i=0;i<26;i++){
            visited[i]=0;
        }
        printf("Case #%d:\n",cases+1);
        if(E>0){
            fgets(A,6,stdin);
            for (i=0;i<E;i++){
                fgets(A,6,stdin);
                addAresta(grafo,(int)A[0]-97,(int)A[2]-97);
        }
        for (i = 0;i < V;i++){
            checkConex(grafo,visited,&con,i);
            if(con==1){
                result++;
                printf("\n");
                con = 0;
            }
        }
        printf("%d connected components\n",result);
        printf("\n");
        destroyGraphL(grafo);
    }
    return 0;
}
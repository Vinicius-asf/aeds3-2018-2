#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _GRAFO2_H
#define _GRAFO2_H

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

listadj_noh_pont createNoh(int vert); // criar nó

graphL_pont createGraphL(int nv); // criar grafo

void addAresta(graphL_pont graph, int source, int destination); //adiciona uma aresta
// implementar para grafos direcionados!
void printGraphL(graphL_pont graph); // printa as relações entre os nós

void destroyNoh(listadj_noh_pont noh); // desaloca a memoria de um nó

void destroyGraphL(graphL_pont graph); // desaloca a memoria de todo um grafo

#endif
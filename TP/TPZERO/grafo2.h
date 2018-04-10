#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _GRAFO2_H
#define _GRAFO2_H

typedef struct listadj_noh{
    int vertice;
    struct listadj_noh *prox;
}listadj_noh_obj, *listadj_noh_pont;

typedef struct listadj{
    int nmembros;
    listadj_noh_obj *header;
}listadj_obj, *listadj_pont;

typedef struct graphL{
    int nvertices;
    listadj_pont arrayList;
}graphL_obj, *graphL_pont;

listadj_noh_pont createNoh(int vert);

graphL_pont createGraphL(int nv);

void addAresta(graphL_pont graph, int source, int destination);

void printGraphL(graphL_pont graph);

void destroyNoh(listadj_noh_pont noh);

void destroyGraphL(graphL_pont graph);

#endif
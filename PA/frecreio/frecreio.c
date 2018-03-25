#include <stdio.h>
#include <stdlib.h>

int main(){
    int N=0, M=0, i=0, j=0, cpos;
    int P[1000],Po[1000];
    scanf("%d",&N);
    for(i=0;N-i>0;i++){
        cpos = 0;
        //ler entrada - numero de alunos
        scanf("%d", &M);
        //ler entradas - ordem de chegada dos alunos
        for (j=0;M-j>0;j++){
            scanf("%d", &P[j]);
        }
        //ordenar vetor em Po
        //comparar P e Po para ver quantos mudaram de posição
        //printar a diferença da quantidade de alunos com a troca de posição
        //(M-cpos)
    }
}
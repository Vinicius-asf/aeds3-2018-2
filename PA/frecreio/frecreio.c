#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ordenaBolha(int qordena[],int tam){ //algoritmo de ordenação Bubblesort
    bool trocou = false; //chave de parada da ordenação
    int idx = 0;
    int aux;
    do{
        trocou = false;
        for(idx=0;tam-idx>0;idx++){
            if(qordena[idx]<qordena[idx+1]){ // troca das posições
                aux=qordena[idx+1];
                qordena[idx+1]=qordena[idx];
                qordena[idx]=aux;
                trocou=true; // identifica que houve uma troca e que deve-se percorrer o vertor outra vez
            }
        }
    }while(trocou);
}

int main(){
    int N=0, M=0, i=0, j=0, cpos;
    int P[1000],Po[1000];
    scanf("%d",&N);
    for(i=0;N-i>0;i++){
        cpos = 0;
        //ler entrada -> numero de alunos
        scanf("%d", &M);
        //ler entradas -> ordem de chegada dos alunos
        for (j=0;M-j>0;j++){
            scanf("%d", &P[j]);
            Po[j]=P[j];
        }
        //ordenar vetor em Po
        ordenaBolha(Po,M);
        /* for (j=0;M-j>0;j++){ //print para testar se a ordenação ocorreu da maneira correta
            printf("%d||%d ",P[j],Po[j]);
        }
        printf("\n"); */
        //comparar P e Po para ver quantos mudaram de posição
        for (j=0;M-j>0;j++){
            if(P[j]!=Po[j]){
                cpos+=1;
            }
        }
        //printar a diferença da quantidade de alunos com a troca de posição
        //(M-cpos)
        printf("%d\n",M-cpos);
    }
}
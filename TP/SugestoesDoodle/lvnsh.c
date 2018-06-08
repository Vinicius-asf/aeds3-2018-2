#include "lvnsh.h"

int minOperation(int del, int insrt, int sbst){
    // del = (lvnsh[i-1][j])+1
    // insrt = (lvnsh[i][j-1])+1
    // sbst = (lvnsh[i-1][j-1])+cost
    if(del < insrt){
        if(del < sbst){
            //printf ("%d\n", del);
            return del;
        }
        else{
            //printf ("%d\n", sbst);            
            return sbst;
        }
    }
    else if(insrt < sbst){
        //printf ("%d\n", insrt);
        return insrt;
    }
    else{
        //printf ("%d\n", sbst);        
        return sbst;
    }
}

int** createLvnshMatrix(int m, int n){
    int i, j;
    int** lvnsh = (int**)malloc((m+1)*sizeof(int*));
    for (i=0;i<m+1;i++){
        lvnsh[i]=(int*)malloc((n+1)*sizeof(int));
    }

    for (i=0; i<m+1;i++){
        for (j=0; j<n+1; j++){
            lvnsh[i][j]=0;
        }
    }

    for (i = 0; i < m+1; i++){
        lvnsh[i][0] = i;
    }
    for (j = 0; j < n+1; j++){
        lvnsh[0][j] = j;
    }

/*     for (i=0; i<m+1;i++){
        for (j=0; j<n+1; j++){
            printf("%d|",lvnsh[i][j]);
        }
        printf("\n");
    } */
    return lvnsh;
}

void deleteLvnshMatrix(int** matrix, int m){
    for (int i=0;i<m+1;i++){
        free(matrix[i]);
    }
    free(matrix);
}

int levenshteinNumber(char query[], char test[]){
    int m = 0; // tamanho da query
    int n = 0; // tamanho da palavra do dicionario
    int i = 0; // localizador na matriz para a palavra query
    int j = 0; // localizador na matriz para a palavra do dicionário
    int cost = 0; // custo de substituição
    int final = 0;

    m = strlen(query);
    n = strlen(test);

    int** lvnsh = createLvnshMatrix(m,n);

    for (i=1;i < m+1; i++){
        //printf("estagio: %d\n", i);
        for (j=1; j < n+1; j++){
            if(test[j-1] == query[i-1]){
                cost = 0;
            }
            else{
                cost = 1;
            }
            //printf("%d|", lvnsh[i][j]);
            lvnsh[i][j] = minOperation((lvnsh[i-1][j])+1,(lvnsh[i][j-1])+1,(lvnsh[i-1][j-1])+cost);
        }
    }
    final = lvnsh[m][n];
    deleteLvnshMatrix(lvnsh, m);

    return final;
}
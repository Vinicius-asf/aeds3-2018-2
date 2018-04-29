#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void varrerPalavra (char palavra[], int alfabeto[]){
    int j = 0, max = strlen(palavra);
    for (j; j<max; j++){
        alfabeto[palavra[j]-97]++;
    }
}

int checarAlfabeto (int alfabeto[]){
    int i = 0, contador = 0;
    while (i<26){
        if (alfabeto[i]%2!=0){
            contador++;
        }
        alfabeto[i]=0;
        i++;
    }
    // return contador-1;
    if (contador != 0){
        return contador-1;
    }
    else{
        return 0;
    }
}

/* void checarPalindromo(char palavra[], int *contador){
    int i = 0, j = strlen(palavra)-1, begin = 1;
    while (i<j){
        if(palavra[i]==palavra[j]){
            i++;
            j--;
        }
        else{
            i = begin;
            begin ++;
            j = strlen(palavra);
            *contador++;
        }
    }
} */

int main (){
    char word [1002];
    //int counter = 0;
    int alfabeto [26];
    checarAlfabeto(alfabeto);
    while(fgets(word, 1002, stdin) && word[0] != 0){
        //printf("%d:",strlen(word));
        varrerPalavra(word, alfabeto);
        printf("%d\n",checarAlfabeto(alfabeto));
        //printf("\n");
        //checarPalindromo(word,&counter);
        //printf("%d\n",counter);
        //counter = 0;
    }
}
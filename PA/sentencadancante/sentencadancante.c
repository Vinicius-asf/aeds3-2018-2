#include <stdlib.h>
#include <stdio.h>

void uppercase(char* letter){
    *letter-=32;
}

void lowercase(char* letter){
    *letter+=32;
}

int main () {
    char teste[50];
    int i = 0;
    int Case = 0;
    fgets(teste,50,stdin);
    while (teste[i]!=10){
        if (teste[i]!=32){
            if (Case == 0){
                Case = 1;
                if (teste[i] > 96){
                    uppercase(&teste[i]);
                }
            }
            else{
                Case = 0;
                if (teste[i] < 96){
                    lowercase(&teste[i]);
                }
            }
        }
        i++;
    }
    printf("%s",teste);
    return 0;
}
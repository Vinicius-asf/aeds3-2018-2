#include <stdio.h>
#include <stdlib.h>

void pikeFinder(int H1, int H2, int H3, int* pkcounter){ //função que checa se os valores H1 e H3 são ambos maiores ou menores que H2. 
    if (H2>H3 && H2>H1){                                 //Caso sejam, adiciona 1 ao contador de picos
        *pkcounter+=1;
    }
    else if (H2<H3 && H2<H1){
        *pkcounter+=1;
    }
}

int main(){
    int N = 0, i = 0; //N é o inteiro que fala quantos pontos tem a música, i é o inteiro controle do loop interno
    int loop[10000]; //vetor que armazena os valores dos pontos da música
    int pcounter = 0; // inteiro que armazena a quantidade de picos encontrados

    while(scanf("%d",&N) && N!=0){ //laço que acaba quando a entrada de pontos for igual a zero
        pcounter = 0;
        for (i=0;N-i>0;i++){ //pega todos os valores de entrada e os colocam no vetor "loop"
            scanf("%d",&loop[i]);
        }
        for (i=0;N-i>0;i++){
            if (i==N-1){
                pikeFinder(loop[i-1],loop[i],loop[0],&pcounter); //chamando a função que checa os picos no inicio do loop
            }
            else if (i==0){
                pikeFinder(loop[N-1],loop[i],loop[i+1],&pcounter);} // chamando a função que checa os picos no final do loop
            else{
                pikeFinder(loop[i-1],loop[i],loop[i+1],&pcounter); // chamando a função que checa os picos no meio do loop
            }
        }
        printf("%d\n",pcounter); //mostrando o valor do contador de picos
    }
    return 0;
}
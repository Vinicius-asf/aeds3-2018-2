#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vector [100000];
    int tamV = 0;
    int i = 0;
    int sum = 0;
    int calc = 0;
    int aux = 0;

    while(scanf("%d",&tamV) && tamV !=0){
        sum = 0;
        for (i=0;i<tamV;i++){
            scanf("%d", &vector[i]);
            //printf("%d",vector[i]);
        }

        for (i=0; i<tamV;i++){
            if (vector[i]!=(i+1)){
                calc = 2*(vector[i]-(i+1))-1;
                //printf("Calculo: %d\n",calc);
                sum+= calc;
                aux = vector[vector[i] - 1];
                vector[vector[i] - 1] = vector[i];
                vector[i] = aux;
                i = i - 1;
            }
        }
        if (sum%2==0){
            printf("Carlos\n");
        }
        else{
            printf("Marcelo\n");
        }
        //printf("%d\n",sum);
    }
    return 0;
}
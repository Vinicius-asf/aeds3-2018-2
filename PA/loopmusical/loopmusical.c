#include <stdio.h>
#include <stdlib.h>

void pikeFinder(int diff, int* pkcounter, int* variation){
    //printf("%d",diff);
    if (*variation == 0){
        if (diff>0){
            *variation = 1;
        }
        else{
            *variation = -1;
        }
        *pkcounter+=1;
    }
    else{
        if (diff>0 && variation<0){
            *pkcounter += 1;
            *variation = 1;
        }
        else if (diff<0 && variation>0){
            *pkcounter += 1;
            *variation = -1;
        }
    }
    /* if (Hi2>Hi3 && Hi2>Hi1){
        *pkcounter += 1;
    }
    else if(Hi2<Hi3 && Hi2<Hi1){
        *pkcounter += 1;
    } */
}

int main(){
    int N = 0, i = 0;
    int loop[10000];
    int pcounter = 0, vrtn = 0;
    //printf("Antes do while\n");

    while(scanf("%d",&N) && N!=0){
        pcounter = 0;
        vrtn = 0;
        //printf("Antes do for\n");
        for (i=0;N-i>0;i++){
            scanf("%d",&loop[i]);
            //printf("%d",loop[i]);           
        }
        for (i=0;N-i>0;i++){
            printf("%d,%d,%d",loop[i],loop[i+1],loop[i]-loop[i+1]);
            printf("Rodando: contador = %d variacao = %d\n",pcounter,vrtn);            
            if (i==N-1){
                pikeFinder(loop[i]-loop[0],&pcounter,&vrtn);
            }
            else{
                pikeFinder(loop[i]-loop[i+1],&pcounter,&vrtn);
            }
            printf("Rodando: contador = %d variacao = %d\n",pcounter,vrtn);
        }
        //pikeFinder(loop[i-1]-loop[0],&pcounter,&vrtn);
        printf("%d\n",pcounter);
    }
    return 0;
}
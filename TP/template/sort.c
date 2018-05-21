// =----------------------------------------------------------=
// =                           AVISO:                         =
// =                   MODIFIQUE ESTE ARQUIVO!                =
// = Aqui, você deve implementar, obrigatoriamente, essas     =
// = duas funções:                                            =
// =     - `a_menor_que_b`: deve retornar quando uma string   =
// =        é menor que a outra (ambos com o mesmo tamanho);  =
// =     - `external_sort`: aqui, você deverá implementar o   =
// =        seu trabalho. Ordene os registros em `input_file` =
// =        e escreva-os em `output_file`, usando somente     =
// =        `memory` KB de memória.                           =
// =                                                          =
// = Instruções:                                              =
// =     - use a função `mathias_malloc` ao invés de          =
// =       `malloc`;                                          =
// =     - use a função `mathias_free` ao invés de `free`;    =
// =     - lembre-se que você tem somente `memory` KB de      =
// =       memória;                                           =
// =     - note que a sua implementação de `a_menor_que_b`    =
// =       afetará o resultado da verificação da resposta.    =
// =                                                          =
// = Dicas:                                                   =
// =     - você pode usar a sua função `a_menor_que_b` em     =
// =       sua implementação da função `external_sort`;       =
// =                                                          =
// =                      BOM TRABALHO!                       =
// =----------------------------------------------------------=

#include <stdio.h>
#include <string.h>
#include "mem.h"

// Parâmetros:
//     - a: uma cadeia de caracteres de tamanho `len`;
//     - b: uma cadeia de caracteres de tamanho `len`;
//     - len: o tamanho (quantidade de bytes) de `a` e `b`.
// Essa função deve retornar 1, se `a` é menor que `b` (`a` deve vir antes de `b` no
// arquivo), e 0 caso contrário.
// Ela também é usada para verificação da ordenação! Então, se você implementá-la
// erroneamente, a verificação também estará errada! 
int a_menor_que_b(char* a, char* b, int len) {
    int i = 0;
    //printf("%s%s", a, b);
    i = strcmp(a,b);
    if(i < 0) {
        //printf("A menor que B\n");
        return 0;
    }
    else {
        //printf("B menor que A\n");
        return 1;
    }
}

// Parâmetros:
//     - input_file: o nome do arquivo com os registros de entrada;
//     - output_file: o nome do arquivo com os registros de entrada ordenados;
//     - memory: o limite de memória a ser usado.
// Essa função deverá ler todos registros do arquivo `input_file`, ordená-los e
// escrevê-los em `output_file`, usando memória menor ou igual a `memory`. Lembre-se
// de fechar todos os arquivos que você usar por aqui!!
void external_sort(const char* input_file, const char* output_file, unsigned int memory) {
    //printf("Inicializando os arquivos\n");
    
    int crt_blk = 0; //controle de criação de blocos
    int limit = 0; //tamanho das linhas
    int compare = 0; //comparação de strings
    int filesize = 0; //tamanho total do arquivo

    char auxfile0 [] = "aux0.txt";
    char auxfile1 [] = "aux1.txt";
    char auxfile2 [] = "aux2.txt";
    char auxfile3 [] = "aux3.txt";

    FILE *input;
    input = fopen(input_file, "r");
    fscanf(input, "%d\n", &limit);
    //fgets(&limit, 5, input);
    //printf("Tamanho das linhas: %d\n", limit);
    
    FILE *aux0;
    FILE *aux1;
    FILE *aux2;
    FILE *aux3;

    aux0 = fopen(auxfile0, "w");
    aux1 = fopen(auxfile1, "w");
    //aux2 = fopen(auxfile2, "w");
    //aux3 = fopen(auxfile3, "w");
    
    char *strA = (char*)mathias_malloc(sizeof(char)*limit + 2);
    char *strB = (char*)mathias_malloc(sizeof(char)*limit + 2);
    
    //printf("Iniciando a criação dos blocos iniciais\n");

    while(1){
        fgets(strA, limit+3, input);
        fgets(strB, limit+3, input);
        if(feof(input)){
            break;
        }
        compare = a_menor_que_b(strA,strB,limit);
        if (compare == 0){
            if (crt_blk == 0){
                fputs(strA, aux0);
                fputs(strB, aux0);
                crt_blk = 1;             
            }
            else{
                fputs(strA, aux1);
                fputs(strB, aux1);
                crt_blk = 0;    
            }
        }
        else{
            if (crt_blk == 0){
                fputs(strB, aux0);                
                fputs(strA, aux0);
                crt_blk = 1;
            }
            else{
                fputs(strB, aux1); 
                fputs(strA, aux1);
                crt_blk = 0;
            }
        }
        filesize += 2;
    }

    fclose(input);
    fclose(aux0);
    fclose(aux1);
    int blk = 2; //controle de intercalação
    int blk_stage = 1;//fase de intercalação

    //printf("Tamanho do arquivo: %d\n", filesize);
    //printf("Iniciando etapas de intercalação\n");

    int blkast1 = 0; // indicador de tamanho de bloco 1
    int blkast2 = 0; // indicador de tamanho de bloco 2
    int aux_size = 0;
    crt_blk = 0;// 0 - arquivo 0 ou 2; 1 - arquivo 1 ou 3

    while(blk<filesize){
        // printf("Estagio: %d, Bloco: %d\n", blk_stage, blk);
        if(blk_stage%2!=0){ //etapa ímpar
            aux0 = fopen(auxfile0, "r");
            aux1 = fopen(auxfile1, "r");
            aux2 = fopen(auxfile2, "w");
            aux3 = fopen(auxfile3, "w");
            while (aux_size < filesize){
                if (blkast1 >= blk && blkast2 >= blk){ //
                    // printf("acabou os dois blocos\n");
                    if(crt_blk == 0){
                        crt_blk = 1;
                    }
                    else{
                        crt_blk = 0;
                    }
                    blkast1 = 0;
                    blkast2 = 0;
                }
                else if (blkast1 >= blk || fgets(strA, limit+3, aux0) == NULL){ // 
                    // printf("acabou o bloco de 0\n");
                    //while(blkast2<blk){
                        fgets(strB, limit+3, aux1);
                        if(crt_blk == 0){
                            fputs(strB, aux2);
                            blkast2 += 1;
                        }
                        else{
                            fputs(strB, aux3);
                            blkast2 += 1;
                        }
                        aux_size+=1;
                    //}
                }
                else if (blkast2 >= blk || fgets(strB, limit+3, aux1) == NULL){// 
                    // printf("acabou o bloco de 1\n");
                    //while(blkast1<blk){
                        //fgets(strA, limit+3, aux0);
                        if(crt_blk == 0){
                            fputs(strA, aux2);
                            blkast1 += 1;
                        }
                        else{
                            fputs(strA, aux3);                     
                            blkast1 += 1;
                        }
                        aux_size+=1;
                   // }
                }
                else{// nenhum dos blocos acabaram
                    compare = a_menor_que_b(strA, strB, limit);
                    if (compare == 0){
                        if(crt_blk == 0){
                            fputs(strA, aux2);
                            fseek(aux1, -(limit+2), SEEK_CUR);
                            blkast1 += 1;
                        }
                        else{
                            fputs(strA, aux3);
                            fseek(aux1, -(limit+2), SEEK_CUR);
                            blkast1 += 1;
                        }
                    }
                    else{
                        if(crt_blk == 0){
                            fputs(strB, aux2);
                            fseek(aux0, -(limit+2), SEEK_CUR);
                            blkast2 += 1;
                        }
                        else{
                            fputs(strB, aux3);
                            fseek(aux0, -(limit+2), SEEK_CUR);                            
                            blkast2 += 1;
                        }
                    }
                    aux_size+=1;
                }

            }
        }
        else{ //etapa par
            aux0 = fopen(auxfile0, "w");
            aux1 = fopen(auxfile1, "w");
            aux2 = fopen(auxfile2, "r");
            aux3 = fopen(auxfile3, "r");
            while (aux_size < filesize){
                if (blkast1 >= blk && blkast2 >= blk){ //
                    // printf("acabou os dois blocos\n");
                    if(crt_blk == 0){
                        crt_blk = 1;
                    }
                    else{
                        crt_blk = 0;
                    }
                    blkast1 = 0;
                    blkast2 = 0;
                }
                else if (blkast1 >= blk || fgets(strA, limit+3, aux2) == NULL){ // 
                    // printf("acabou o bloco de 0\n");
                    //while(blkast2<blk){
                        fgets(strB, limit+3, aux3);
                        if(crt_blk == 0){
                            fputs(strB, aux0);
                            blkast2 += 1;
                        }
                        else{
                            fputs(strB, aux1);
                            blkast2 += 1;
                        }
                        aux_size+=1;
                    //}
                }
                else if (blkast2 >= blk || fgets(strB, limit+3, aux3) == NULL){// 
                    // printf("acabou o bloco de 1\n");
                    //while(blkast1<blk){
                        //fgets(strA, limit+3, aux2);
                        if(crt_blk == 0){
                            fputs(strA, aux0);
                            blkast1 += 1;
                        }
                        else{
                            fputs(strA, aux1);
                            blkast1 += 1;
                        }
                        aux_size+=1;
                    //}
                }
                else{// nenhum dos blocos acabaram
                    compare = a_menor_que_b(strA, strB, limit);
                    if (compare == 0){
                        if(crt_blk == 0){
                            fputs(strA, aux0);
                            fseek(aux3, -(limit+2), SEEK_CUR);                          
                            blkast1 += 1;
                        }
                        else{
                            fputs(strA, aux1);
                            fseek(aux3, -(limit+2), SEEK_CUR);                                                      
                            blkast1 += 1;
                        }
                    }
                    else{
                        if(crt_blk == 0){
                            fputs(strB, aux0);
                            fseek(aux2, -(limit+2), SEEK_CUR);                                                      
                            blkast2 += 1;
                        }
                        else{
                            fputs(strB, aux1);
                            fseek(aux2, -(limit+2), SEEK_CUR);                                                      
                            blkast2 += 1;
                        }
                    }
                    aux_size+=1;
                }

            }
        }
        fclose(aux0);
        fclose(aux1);
        fclose(aux2);
        fclose(aux3);
        blk = blk*2;
        blk_stage+=1;
        aux_size = 0;
        blkast1 = 0;
        blkast2 = 0; 
        crt_blk = 0;      
    }
    if(blk_stage%2==0){
        aux0 = fopen(auxfile0, "r");
    }
    else{
        aux0 = fopen(auxfile2, "r");
    }
    // printf("Fim do processo\n");
    FILE *output = fopen(output_file, "w");
    fprintf(output, "%d\n",limit);
    //for(filesize; filesize>0; filesize--){
    while(filesize>0){
        fgets(strB, limit+3, aux0);
        fputs(strB,output);
        filesize--;
    }
    fclose(output);
    fclose(aux0);
    mathias_free(strA);
    mathias_free(strB);
}

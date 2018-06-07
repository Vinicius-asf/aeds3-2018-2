#include"lvnsh.h"

int main(int argc, char const *argv[])
{
    int result;
    int wordFound = 0; // contagem de palavras encontradas
    int nWord = 0; // contagem de palavras do dicionario
    int pChanges = 0; // quantos movimentos podem ser feitos

    scanf("%d\n%d", &nWord, &pChanges);
    //result = levenshteinNumber(fonte, dic);
    printf("Palavras: %d, Trocas: %d, Final: %d\n", pChanges, nWord, result);
    return 0;
}

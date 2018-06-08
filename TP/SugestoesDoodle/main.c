#include "lvnsh.h"
#include "wordtape.h"

int main(int argc, char const *argv[])
{
    unsigned int result = 0; // armazena o resultado do cálculo da distância
    unsigned int wordFound = 0; // contagem de palavras encontradas
    unsigned int nWord = 0; // contagem de palavras do dicionario
    unsigned int pChanges = 0; // quantos movimentos podem ser feitos
    char query [100]; // palavra chave
    char test [10000]; // palavra de teste
    int i; // contador de loop
    unsigned int charMax = 0; // tamanho máximo da palavra teste para ser aceito
    unsigned int charMin = 0; // tamanho mínimo da palavra teste para ser aceito
    wordtape tape;

    scanf("%d\n%d", &nWord, &pChanges);

    tape = (wordtape)malloc(sizeof(word)*nWord);

    scanf("%s\n", query);

    charMax = strlen(query) + pChanges;
    charMin = strlen(query) - pChanges;
    //while(scanf("%s\n", test) != EOF){
    //printf("Palavra-chave: %s NPalavras: %u NTrocas: %u\n", query, nWord, pChanges);
    for (i=0; i<nWord; i++){
        scanf("%s\n", test);
        if((strlen(test)<=charMax)
        &&
        (strlen(test)>=charMin)){
            //printf("Palavra: %s rola\n", test);
            result = levenshteinNumber(query,test);
            if(result <= pChanges){
                //tape[wordFound].word = test;
                strcpy(tape[wordFound].word, test);
                tape[wordFound].op = result;
                //printf("%d:%s-%u\n", wordFound,tape[wordFound].word,tape[wordFound].op);
                wordFound++;
            }
        }
        else{
            //printf("Palavra: %s não rola\n", test);
        }
    }

    qsort(tape, nWord, sizeof(word), comparaPalavra);

    for(i = nWord-wordFound; i<=nWord ;i++){
        printf("%s\n",tape[i].word);
    }

    //printf("Palavra: %s, Trocas: %u, Final: %d\n", test, nWord, result);

    free(tape);
    return 0;
}

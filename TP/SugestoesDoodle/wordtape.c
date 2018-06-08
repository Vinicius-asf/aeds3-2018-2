#include "wordtape.h"

int comparaPalavra(const void* a, const void* b){
    word* word1 = (word*)a;
    word* word2 = (word*)b;
    int test = word1->op - word2->op;
    if(test == 0){
        return strcmp(word1->word, word2->word);
    }
    else{
        return test;
    }
}
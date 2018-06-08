#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _WORDTAPE_H_
#define _WORDTAPE_H_

typedef struct wordtape{
    char word [10001];
    unsigned int op;
}word, *wordtape;

int comparaPalavra(const void* a,const void* b);

#endif
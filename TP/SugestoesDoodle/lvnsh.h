#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _LVNSH_H_
#define _LVNSH_H_

int minOperation(int del, int insrt, int sbst);
    // delete = (lvnsh[i-1][j])+1
    // insert = (lvnsh[i][j-1])+1
    // subst = (lvnsh[i-1][j-1])+cost
int levenshteinNumber(char query[], char test[]);

#endif
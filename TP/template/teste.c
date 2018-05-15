#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "mem.h"

int main (){
    char input [] = "test.txt";
    char output [] = "output.txt";
    external_sort(input,output,1024);
    return 0;
}
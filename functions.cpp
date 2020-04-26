#include <iostream>
#include <stdio.h>
#include <string.h>

char* slicing(char* entrada,int i){
    char* slicedEntrada = (char*) malloc(i*sizeof(char));
    for(int a = 0; a < i; a++){
        slicedEntrada[a] = entrada[a];
    }
    return slicedEntrada;
}
#include <iostream>
#include <stdio.h>
#include <string.h>

char* slicing(char* entrada,int i){
    char slicedEntrada[100];
    for(int a = 0; a < i; a++){
        slicedEntrada[a] = entrada[a];
    }
    return slicedEntrada;
}
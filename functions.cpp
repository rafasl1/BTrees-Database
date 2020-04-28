#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char* slicing(char* entrada,int i){
    char* slicedEntrada = (char*) malloc(i*sizeof(char));
    for(int a = 0; a < i; a++){
        slicedEntrada[a] = entrada[a];
    }
    cout << slicedEntrada << endl;
    return slicedEntrada;
}
/*
void insere(FILE* documento, char* str){
    documento = fopen("memoriaSecundaria.txt","w");
    fwrite(str, 1, sizeof(str), documento);
    cout << "REGISTRO INSERIDO COM SUCESSO" << endl;
    fclose(documento);
}*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
char* slicing(char* entrada,int i){
    char* slicedEntrada = (char*) malloc(i*sizeof(char));
    for(int a = 0; a < i; a++){
        slicedEntrada[a] = entrada[a];
    }
    cout << slicedEntrada << endl;
    return slicedEntrada;
}*/

bool palavrasIguais(char palavra1[],char palavra2[], int n){
    for(int i = 0; i < n; i++){
        if(!(palavra1[i]==palavra2[i])) return false;
    }
    return true;
}
/*
void insere(FILE* documento, char* str){
    documento = fopen("memoriaSecundaria.txt","w");
    fwrite(str, 1, sizeof(str), documento);
    cout << "REGISTRO INSERIDO COM SUCESSO" << endl;
    fclose(documento);
}*/
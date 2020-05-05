#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


bool palavrasIguais(char palavra1[],char palavra2[], int n){
    for(int i = 0; i < n; i++){
        if(!(palavra1[i]==palavra2[i])) return false;
    }
    return true;
}

void imprimeFragmentacao(float bytesOcupados, float bytesLivres){
    cout << "BYTES OCUPADOS: " << bytesOcupados << " BYTES LIVRES: " << bytesLivres << " FRAGMENTACAO: " << bytesLivres * 100 / bytesOcupados << "%" << endl;
}

void buscaRegistro(){
    cout << "CPF = " << endl;
    cout << "NOME = " << endl;
    cout << "SOBRENOME = " << endl;
    cout << "CURSO = " << endl;
    cout << "SEXO = " << endl;
    cout << "DATA_NASCIMENTO = " << endl;

    /*
    se n encontrar cpf
    cout << "NENHUM REGISTRO ENCONTRADO" << endl;
    */
}

void atualizaRegistro(){
    cout << "REGISTRO ATUALIZADO COM SUCESSO" << endl;
}

void removeRegistro(){
    cout << "REGISTRO REMOVIDO COM SUCESSO" << endl;
}

/*
char* slicing(char* entrada,int i){
    char* slicedEntrada = (char*) malloc(i*sizeof(char));
    for(int a = 0; a < i; a++){
        slicedEntrada[a] = entrada[a];
    }
    cout << slicedEntrada << endl;
    return slicedEntrada;

void insere(FILE* documento, char* str){
    documento = fopen("memoriaSecundaria.txt","w");
    fwrite(str, 1, sizeof(str), documento);
    cout << "REGISTRO INSERIDO COM SUCESSO" << endl;
    fclose(documento);
}*/
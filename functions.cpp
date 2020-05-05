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

void salvaDadosDaInsercao(char entrada[], int n, char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]){
    char delimitador[2] = ",", delimitadorFinal[2] = ")";
    int contadorDeVirgulas = 0, iteradorDeCampos = 0;
    for(int i = 8; i < n; i++){
        if(entrada[i] == delimitadorFinal[1]){
            break;
        }
        if(entrada[i] == delimitador[1]){
            iteradorDeCampos = 0;
            contadorDeVirgulas++;
            continue;
        }
        if(contadorDeVirgulas == 0){
            cpf[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else if(contadorDeVirgulas == 1){
            nome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else if(contadorDeVirgulas == 2){
            sobrenome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else if(contadorDeVirgulas == 3){
            curso[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else if(contadorDeVirgulas == 4){
            sexo[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else if(contadorDeVirgulas == 5){
            dataNascimento[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
        }else{
            cout << "Deu merda no contador" << endl;
        }
    }
}

void imprimeFragmentacao(float bytesOcupados, float bytesLivres){
    cout << "BYTES OCUPADOS: " << bytesOcupados << " BYTES LIVRES: " << bytesLivres << " FRAGMENTACAO: " << bytesLivres * 100 / bytesOcupados << "%" << endl;
}

void buscaRegistro(char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]){
    cout << "CPF = " << cpf << endl;
    cout << "NOME = " << nome << endl;
    cout << "SOBRENOME = " << sobrenome << endl;
    cout << "CURSO = " << curso << endl;
    cout << "SEXO = " << sexo << endl;
    cout << "DATA_NASCIMENTO = " << dataNascimento << endl;

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
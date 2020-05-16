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


void salvaDadosInsere(char entrada[], int n, char* cpf, char* nome, char* sobrenome, char* curso, char* sexo, char* dataNascimento){
    char delimitador[2] = ",", delimitadorFinal[2] = ")";
    int contadorDeVirgulas = 0, iteradorDeCampos = 0;
    for(int i = 8; i < n; i++){
        if(entrada[i] == delimitadorFinal[0]){
            break;
        }
        if(entrada[i] == delimitador[0]){
            iteradorDeCampos = 0;
            contadorDeVirgulas++;
            continue;
        }
        if(contadorDeVirgulas == 0){
            cpf[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 1){
            nome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 2){
            sobrenome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 3){
            curso[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 4){
            sexo[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 5){
            dataNascimento[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else{
            cout << "Deu ruim no contador" << endl;
        }
    }
}

void imprimeFragmentacao(float bytesOcupados, float bytesLivres){
    cout << "BYTES OCUPADOS: " << bytesOcupados << " BYTES LIVRES: " << bytesLivres << " FRAGMENTACAO: " << bytesLivres * 100 / bytesOcupados << "%" << endl;
}

void atualizaRegistro(/*Registro* reg, char* cpf, char* nome, char* sobrenome, char* curso, char* sexo, char* dataNascimento*/){
/*    reg->cpf = cpf;
    reg->nome = nome;
    reg->sobrenome = sobrenome;
    reg->curso = curso;
    reg->sexo = sexo;
    reg->dataNascimento = dataNascimento;*/
    cout << "REGISTRO ATUALIZADO COM SUCESSO" << endl;
}

void removeRegistro(int cpf){
    cout << "REGISTRO REMOVIDO COM SUCESSO" << endl;
}
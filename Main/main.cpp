#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "funcoesAuxiliares.cpp"
#include "funcoesRegistro.cpp"
#include "functionsArvoreB.cpp"

using namespace std;

int main(){
    
    Arv_B arvore;
    criaArvoreB(&arvore);

    char entrada[100] = {};
    char fechar[] = "FECHA";

    char* cpf = (char*)malloc(sizeof(char)*10);
    char* nome = (char*)malloc(sizeof(char)*50);
    char* sobrenome = (char*)malloc(sizeof(char)*50);
    char* curso = (char*)malloc(sizeof(char)*50);
    char* sexo = (char*)malloc(sizeof(char)*2);
    char* dataNascimento = (char*)malloc(sizeof(char)*11);
    
    do {
        cin.getline (entrada,100);

        char insere[] = {"INSERE("};
        char busca[] = {"BUSCA"};
        char remove[] = {"REMOVE"};
        char atualiza[] = {"ATUALIZA"};
        char imprimeFrag[] = {"IMPRIME_FRAGMENTACAO"};

        if(palavrasIguais(entrada, insere, 7)){
            // insere os dados no arquivo de dados e insere o cpf no arquivo de indice
            // tem que verificar se vai ter um bloco disponível no arquivo de dados
            salvaDadosInsere(entrada,100,cpf,nome,sobrenome,curso,sexo,dataNascimento);
            Registro registro;
            colocaDadosNoRegistro(&registro, cpf,nome,sobrenome,curso,sexo,dataNascimento);
            mostraRegistro(registro);
            arq = fopen("memoriaSecundaria.txt","a+");
            gravaRegistro(registro);
            printf("NOVO REGISTRO CRIADO COM SUCESSO\n");
            fechaArq();

        }else if(palavrasIguais(entrada, busca, 5)){ 
            // a busca procura um cpf na arvore b e devolve os dados referentes a esse cpf no arquivo de dados
            arq = fopen("memoriaSecundaria.txt","r+");
            Registro reg;
            while(leProximoRegistro(&reg)) {
                cout << "---------" << endl;
                mostraRegistro(reg);
            }
            cout << "---------" << endl;

            fechaArq();

        }else if(palavrasIguais(entrada, remove, 6)){
            int cpf;
            removeRegistro(cpf);
            
        }else if(palavrasIguais(entrada, atualiza, 8)){
            atualizaRegistro();
            
        }else if(palavrasIguais(entrada, imprimeFrag, 20)){
            imprimeFragmentacao(143,28);
            
        }else if(palavrasIguais(entrada, fechar, 5)){
            printf("ENCERRANDO\n");
        }
        else{
           printf("Entrada invalida\n");
        }

    } while(strcmp(entrada,fechar));

    return 0;
}
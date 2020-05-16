#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "Funcoes.cpp"
#include "funcoesRegistro.cpp"

using namespace std;

int main(){
    
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
         /*   documento = fopen("memoriaSecundaria.txt","a+");
            fwrite(str, 1, sizeof(str), documento);
            fclose(documento);*/
            //salvaDadosDaInsercao(entrada,100,cpf,nome,sobrenome,curso,sexo,dataNascimento);
            salvaDadosInsere(entrada,100,cpf,nome,sobrenome,curso,sexo,dataNascimento);
            Registro registro;
            colocaDadosNoRegistro(&registro, cpf,nome,sobrenome,curso,sexo,dataNascimento);
            mostraRegistro(registro);
            arq = fopen("memoriaSecundaria.txt","a+");
            gravaRegistro(registro);
            printf("NOVO REGISTRO CRIADO COM SUCESSO\n");
            fechaArq();

        }else if(palavrasIguais(entrada, busca, 5)){
            //buscaRegistro(cpf,nome,sobrenome,curso,sexo,dataNascimento);
            arq = fopen("memoriaSecundaria.txt","r+");
            Registro reg;
            while(leProximoRegistro(&reg)) {
                cout << "---------" << endl;
                mostraRegistro(reg);
            }
            cout << "---------" << endl;

            fechaArq();

        }else if(palavrasIguais(entrada, remove, 6)){
            removeRegistro();
            
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
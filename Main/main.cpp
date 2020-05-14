#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "Funcoes.cpp"
#include "Buffer.cpp"
#include "Registro.cpp"

using namespace std;

int main(){
    
    char entrada[100] = {};
    char fechar[] = "FECHA";
    char cpf[10] = {};
    char nome[50] = {};
    char sobrenome[50] = {};
    char curso[50] = {};
    char sexo[2] = {};
    char dataNascimento[11] = {};
    
    do {
        cin.getline (entrada,100);
        cout << entrada << endl;

        char insere[] = {"INSERE("};
        char busca[] = {"BUSCA"};
        char remove[] = {"REMOVE"};
        char atualiza[] = {"ATUALIZA"};
        char imprimeFrag[] = {"IMPRIME_FRAGMENTACAO"};

        if(palavrasIguais(entrada, insere, 7)){
         /*   documento = fopen("memoriaSecundaria.txt","a+");
            fwrite(str, 1, sizeof(str), documento);
            printf("NOVO REGISTRO CRIADO COM SUCESSO\n");
            fclose(documento);*/
            Registro registro = leRegistroStdin(cpf,nome,sobrenome,curso,sexo,dataNascimento);
            gravaRegistro(registro);
            salvaDadosDaInsercao(entrada,100,cpf,nome,sobrenome,curso,sexo,dataNascimento);
            cout << "Deu bom" << endl;

        }else if(palavrasIguais(entrada, busca, 5)){
            buscaRegistro(cpf,nome,sobrenome,curso,sexo,dataNascimento);
            
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
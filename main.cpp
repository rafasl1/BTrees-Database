#include <iostream>
#include <stdio.h>
#include <string.h>
#include "functions.cpp"
#include <string>

using namespace std;

int main(){
    
    char entrada[100] = {}; // a maior entrada do Freire tinha 79
    char fechar[] = "FECHA";
   // FILE* documento;
    char str[] = {"Rafa"};
    char cpf[10] = {};
    char nome[15] = {};
    char sobrenome[25] = {};
    char curso[30] = {};
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
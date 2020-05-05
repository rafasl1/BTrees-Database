#include <iostream>
#include <stdio.h>
#include <string.h>
#include "functions.cpp"

using namespace std;

int main(){
    
    char entrada[100]; // a maior entrada do Freire tinha 79
    char fechar[] = "FECHA";
    FILE* documento;
    char str[] = {"Rafa"};
    
    do {

        cin >> entrada;

        char insere[] = {"INSERE"};
        char busca[] = {"BUSCA"};
        char remove[] = {"REMOVE"};
        char atualiza[] = {"ATUALIZA"};
        char imprimeFrag[] = {"IMPRIME_FRAGMENTACAO"};

        if(palavrasIguais(entrada, insere, 6)){
            documento = fopen("memoriaSecundaria.txt","a+");
            fwrite(str, 1, sizeof(str), documento);
            printf("NOVO REGISTRO CRIADO COM SUCESSO\n");
            fclose(documento);

        }else if(palavrasIguais(entrada, busca, 5)){
            buscaRegistro();
            
        }else if(palavrasIguais(entrada, remove, 6)){
            removeRegistro();
            
        }else if(palavrasIguais(entrada, atualiza, 8)){
            atualizaRegistro();
            
        }else if(palavrasIguais(entrada, imprimeFrag, 20)){
            imprimeFragmentacao(143,28);
            
        }else if(palavrasIguais(entrada, fechar, 6)){
            printf("Voce saiu do programa!\n");
        }
        else{
           printf("Entrada invalida\n");
        }

    } while(strcmp(entrada,fechar));

    return 0;
}
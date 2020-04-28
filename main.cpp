#include <iostream>
#include <stdio.h>
#include <string.h>
#include "functions.cpp"

using namespace std;

int main(){
    
    char entrada[100]; // a maior entrada do Freire tinha 79
    char fechar[] = "FECHAR";
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
            documento = fopen("memoriaSecundaria.txt","w");
            fwrite(str, 1, sizeof(str), documento);
            printf("REGISTRO INSERIDO COM SUCESSO\n");
            fclose(documento);

        }else if(palavrasIguais(entrada, busca, 5)){
            // busca()
            printf("Busca\n");
            
        }else if(palavrasIguais(entrada, remove, 6)){
            // remove()
            printf("Removeu\n");
            
        }else if(palavrasIguais(entrada, atualiza, 8)){
            // atualiza
            printf("Atualizou\n");
            
        }else if(palavrasIguais(entrada, imprimeFrag, 20)){
            // imprimeFrag()
            printf("Fragmentacao impressa\n");
            
        }else if(palavrasIguais(entrada, fechar, 6)){
            printf("Voce saiu do programa!\n");
        }
        else{
           printf("Entrada invalida\n");
        }

    } while(strcmp(entrada,fechar));

    return 0;
}
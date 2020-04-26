#include <iostream>
#include <stdio.h>
#include <string.h>
#include "functions.cpp"

using namespace std;

int main(){
    
    char entrada[100]; // a maior entrada do Freire tinha 79
    const char fechar[] = "FECHAR";
    
    do {

        cin >> entrada;
        
        char* insere = slicing(entrada,6);
        char* busca = slicing(entrada,5);
        char* remove = slicing(entrada,6);
        char* atualiza = slicing(entrada,8);
        char* imprimeFrag = slicing(entrada,20);

        if(strcmp(insere,"INSERE")){
            // insere()

        }else if(strcmp(busca,"BUSCA")){
            // busca()
            
        }else if(strcmp(remove,"REMOVE")){
            // remove()
            
        }else if(strcmp(atualiza,"ATUALIZA")){
            // atualiza
            
        }else if(strcmp(imprimeFrag,"IMPRIME_FRAGMENTACAO")){
            // imprimeFrag()
            
        }

    } while(strcmp(entrada,fechar));

    cout << "Vc saiu do programa";

    return 0;
}
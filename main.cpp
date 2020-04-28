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

        char insere[] = {"INSERE"};
        char busca[] = {"BUSCA"};
        char remove[] = {"REMOVE"};
        char atualiza[] = {"ATUALIZA"};
        char imprimeFrag[] = {"IMPRIME_FRAGMENTACAO"};

        if(palavrasIguais(entrada, insere, 6)){
            // insere()
            cout << "Insere" << endl;

        }else if(palavrasIguais(entrada, busca, 5)){
            // busca()
            cout << "Busca" << endl;
            
        }else if(palavrasIguais(entrada, remove, 6)){
            // remove()
            cout << "Removeu" << endl;
            
        }else if(palavrasIguais(entrada, atualiza, 8)){
            // atualiza
            cout << "Atualizou urru" << endl;
            
        }else if(palavrasIguais(entrada, imprimeFrag, 20)){
            // imprimeFrag()
            cout << "Fragmentacao impressa" << endl;
            
        }else{
            cout << "Entrada invalida" << endl;
        }

    } while(strcmp(entrada,fechar));

    cout << "Vc saiu do programa";

    return 0;
}
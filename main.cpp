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

        if(strcmp(insere,"INSERE")==0){
            // insere()
            cout << "Insere" << endl;

        }else if(strcmp(busca,"BUSCA")==0){
            // busca()
            cout << "Busca" << endl;
            
        }else if(strcmp(remove,"REMOVE")==0){
            // remove()
            cout << "Removeu" << endl;
            
        }else if(strcmp(atualiza,"ATUALIZA")==0){
            // atualiza
            cout << "Atualizou urru" << endl;
            
        }else if(strcmp(imprimeFrag,"IMPRIME_FRAGMENTACAO")==0){
            // imprimeFrag()
            cout << "Fragmentacao impressa" << endl;
            
        }else{
            cout << "Entrada invalida" << endl;
        }

    } while(strcmp(entrada,fechar));

    cout << "Vc saiu do programa";

    return 0;
}
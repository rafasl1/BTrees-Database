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
            cout << "Deu certo" << endl;

        }else if(strcmp(busca,"BUSCA")){
            // busca()
            cout << "Deu certo" << endl;
            
        }else if(strcmp(remove,"REMOVE")){
            // remove()
            cout << "Deu certo" << endl;
            
        }else if(strcmp(atualiza,"ATUALIZA")){
            // atualiza
            cout << "Deu certo" << endl;
            
        }else if(strcmp(imprimeFrag,"IMPRIME_FRAGMENTACAO")){
            // imprimeFrag()
            cout << "Deu certo" << endl;
            
        }else{
            cout << "Deu tudo errado" << endl;
        }

    } while(strcmp(entrada,fechar));

    cout << "Vc saiu do programa";

    return 0;
}
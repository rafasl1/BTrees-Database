#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    
    char entrada[100]; // a maior entrada do Freire tinha 79
    const char fechar[] = "FECHAR";
    
    do {

        cin >> entrada;
        cout << "Si fode ai cara" << endl;

    } while(strcmp(entrada,fechar));

    cout << "Vc saiu do programa";

    return 0;
}
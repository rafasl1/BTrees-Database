#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    char virgula[2] = {","};
    char entrada[5] = {};

    cin >> entrada;
    cout << "Sua entrada foi: " << entrada << endl; 
    cout << "Comparando com " << virgula[0] << " o resultado foi: " << endl;
    if(entrada[0] == virgula[0]){
        cout << "Eh igual essa merda" << endl;
    }else{
        cout << "Deu ruim caralho" << endl;
    }

    return 0;
}
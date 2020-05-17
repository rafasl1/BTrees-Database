#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


bool palavrasIguais(char palavra1[],char palavra2[], int n){
    for(int i = 0; i < n; i++){
        if(!(palavra1[i]==palavra2[i])) return false;
    }
    return true;
}


void salvaDadosInsere(char entrada[], int n, char* cpf, char* nome, char* sobrenome, char* curso, char* sexo, char* dataNascimento){
    char delimitador[2] = ",", delimitadorFinal[2] = ")";
    int contadorDeVirgulas = 0, iteradorDeCampos = 0;
    for(int i = 8; i < n; i++){
        if(entrada[i] == delimitadorFinal[0]){
            break;
        }
        if(entrada[i] == delimitador[0]){
            iteradorDeCampos = 0;
            contadorDeVirgulas++;
            continue;
        }
        if(contadorDeVirgulas == 0){
            cpf[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 1){
            nome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 2){
            sobrenome[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 3){
            curso[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 4){
            sexo[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else if(contadorDeVirgulas == 5){
            dataNascimento[iteradorDeCampos] = entrada[i];
            iteradorDeCampos++;
            continue;
        }else{
            cout << "Deu ruim no contador" << endl;
        }
    }
}

void pegaCpfBusca(char entrada[], char* cpf){
    char delimitadorFinal[2] = ")";
    int iterador = 0;
    for(int i = 6; i < 100; i++){
        if(entrada[i] == delimitadorFinal[0]){
            break;
        }
        cpf[iterador++] = entrada[i];
    }
}

void removeRegistro(int cpf){
    // removeNoArvoreB(int cpf);
    cout << "REGISTRO REMOVIDO COM SUCESSO" << endl;
}


// escreve o nó "x" no endereço "end"
/*
void disk_write(No* x, int end) {
    fseek("arquivoDeIndice.txt",3*sizeof(int),SEEK_END);
    write_buffer x->folha
    write_buffer x->nChaves
    write_buffer x->chaves // deve ocupar sizeof(Chave) * (2*t - 1) bytes

   if(x->folha) {
        write_buffer x->endFilhos // deve ocupar sizeof(int) * 2*t bytes
   }

   write_no_disco
}

No* disk_read(int end) {
   fseek("arquivoDeIndice.txt",3*sizeof(int),SEEK_END);
   aloca nó y na memória principal
   buffer <- read_disco // quantos bytes? depende se é ou não folha. Pensa aí!
   y->folha <- read_buffer bool 
   y->nChaves <- read_buffer int 
   y->chaves  <- read_buffer sizeof(Chave) * (2*t - 1) bytes 

   if(y->folha) {  
      y->endFilhos <- read_buffer sizeof(int) * 2*t bytes  
   }

   return y
}*/
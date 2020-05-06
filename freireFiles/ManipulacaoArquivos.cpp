#include <cstring>
#include <iostream>
#include <stdio.h>
#include "ManipulacaoArquivos.h"

using namespace std;

FILE *arq = NULL;
char SEPARADOR[2] = {SEPARADOR_CHAR, '\0'}; // nao usei define para evitar warning
/*
  --------------------------------------------
              Funcoes de gravacao
  --------------------------------------------
*/
void gravaBloco(char* info, int tamBlocoEmBytes) {
   if(arq == NULL) {
      cout << "ERRO: arquivo nao foi aberto." << endl;
      exit(0);
   }

   fwrite(info, tamBlocoEmBytes, 1, arq);
}

void gravaSeparador() {
   gravaBloco(SEPARADOR, 1);
}

void gravaString(char* s) {
   gravaBloco(s, strlen(s));
}

void gravaInt(int* n) {
   gravaBloco((char*)n, sizeof(int));
}
// -------------------------------------------

/*
  --------------------------------------------
             Funcoes de leitura
  --------------------------------------------
*/
Buffer leBloco(int tamBlocoEmBytes) {
   Buffer buffer;

   if(arq == NULL) {
      cout << "ERRO: arquivo nao foi aberto." << endl;
      exit(0);
   }

   fread(buffer.registro, tamBlocoEmBytes, 1, arq);
   buffer.prox = 0;
   return buffer;
}

void leInt(int* n) {
    fread(n, sizeof(int), 1, arq);
}

int leIntDoBuffer(Buffer* buffer) {
   int n = 0;

   for(int i = 0; i < sizeof(int); i++) {
      n += (buffer->registro[buffer->prox++]) << (8 * i);
   }

   buffer->prox++; // "consome o separador"
   return n;
}

void leStringDoBuffer(Buffer* buffer, char* s) {
    int i = 0;

    while (buffer->registro[buffer->prox] != SEPARADOR_CHAR) {
      s[i++] = buffer->registro[buffer->prox++];
    }

    s[i] = '\0';
    buffer->prox++; // "consome o separador"
}
// -------------------------------------------

/*
  --------------------------------------------
  Funcoes de abertura e fechamento de arquivos
  --------------------------------------------
*/
void abreArqEscrita(char* nomeArq) {
   arq = fopen(nomeArq, "wb");
}

void abreArqLeitura(char* nomeArq) {
   arq = fopen(nomeArq, "rb");
}

void fechaArq() {
   fclose(arq);
}
// --------------------------------------------

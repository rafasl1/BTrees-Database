#include <cstring>
#include <iostream>
#include <stdio.h>
#include "RegistrosTamanhoVariavel.h"
#include "ManipulacaoArquivos.h"

using namespace std;

void gravaRegistro(Registro reg) {
   int tamReg = sizeof(int) + strlen(reg.nome) + strlen(reg.sobrenome) + 3;
   gravaInt(&tamReg);
   gravaInt(&reg.id);
   gravaSeparador();
   gravaString(reg.nome);
   gravaSeparador();
   gravaString(reg.sobrenome);
   gravaSeparador();
}

bool leProximoRegistro(Registro* reg) {
   int tamReg = 0;
   leInt(&tamReg);

   if(tamReg != 0) {
      Buffer buffer = leBloco(tamReg);
      reg->id = leIntDoBuffer(&buffer);
      leStringDoBuffer(&buffer, reg->nome);
      leStringDoBuffer(&buffer, reg->sobrenome);
      return true;
   } else {
      return false;
   }
}

/*
  --------------------------------------------
  Funcoes de leitura/escrita na stdin/out
  --------------------------------------------
*/
void mostraRegistro(Registro reg) {
   cout << "Id: " << reg.id << endl;
   cout << "Nome: " << reg.nome << endl;
   cout << "Sobrenome: " << reg.sobrenome << endl;
}

void leLinhaStdin(char* s) {
   char c = getc(stdin);
   int i = 0;

   while(c != '\n') {
      s[i++] = (char)c;
      c = getc(stdin);
   }

   s[i] = '\0';
}

Registro leRegistroStdin() {
   Registro reg;
   cout << "Digite o id: ";
   cin >> reg.id;
   getc(stdin); // le lixo ('\n')
   cout << "Digite o nome: ";
   leLinhaStdin(reg.nome);
   cout << "Digite o sobrenome: ";
   leLinhaStdin(reg.sobrenome);
   return reg;
}
// --------------------------------------------

int main(int argc, char **argv) {
   char nomeArq[30];
   int opcao;
   int querGravarMaisRegs = 2;
   cout << "Escolha uma das opcoes (1 - escrita, 2 - leitura): ";
   cin >> opcao;

   switch(opcao) {
      case 1:
         cout << "\nDigite o nome do arquivo para escrita: ";
         cin >> nomeArq;
         abreArqEscrita(nomeArq);

         do {
            Registro reg = leRegistroStdin();
            gravaRegistro(reg);
            cout << "Deseja gravar mais registros? (1 - sim ou 2 - nao): ";
            cin >> querGravarMaisRegs;
         } while(querGravarMaisRegs == 1);

         fechaArq();
         break;

      case 2:
         cout << "\nDigite o nome do arquivo para leitura: ";
         cin >> nomeArq;
         abreArqLeitura(nomeArq);
         Registro reg;

         while(leProximoRegistro(&reg)) {
            cout << "---------" << endl;
            mostraRegistro(reg);
         }
         cout << "---------" << endl;

         fechaArq();
         break;

      default:
         cout << "\nOpcao invalida!\n Tchau, seu babaca!" << endl;
         exit(0);
   }
}

#include "Buffer.cpp"
#define TAM_MAX_STRING 30

using namespace std;

typedef struct Registro {
    char cpf[10];
    char nome[50];
    char sobrenome[50];
    char curso[50];
    char sexo[2];
    char dataNascimento[11];
} Registro;


void gravaRegistro(Registro reg) {
   int tamReg = strlen(reg.cpf) + strlen(reg.nome) + strlen(reg.sobrenome) + 3;
   gravaInt(&tamReg);
   gravaString(reg.cpf);
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
   cout << "CPF: " << reg.cpf << endl;
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

Registro leRegistroStdin(char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]) {
   Registro reg;
   cin >> reg.cpf;
   getc(stdin); // le lixo ('\n')
   leLinhaStdin(reg.nome);
   leLinhaStdin(reg.sobrenome);
   return reg;
}
#include "Buffer.cpp"
#define TAM_MAX_STRING 30

using namespace std;

typedef struct Registro {
   int   id;
   char  nome[TAM_MAX_STRING];
   char  sobrenome[TAM_MAX_STRING];
} Registro;


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
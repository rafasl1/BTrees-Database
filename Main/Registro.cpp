#include "Buffer.cpp"

using namespace std;

typedef struct Registro {
   char* cpf;
   char* nome;
   char* sobrenome;
   char* curso;
   char* sexo;
   char* dataNascimento;
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
      leStringDoBuffer(&buffer,reg->cpf);
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
   cout << "CPF = " << reg.cpf << endl;
   cout << "NOME = " << reg.nome << endl;
   cout << "SOBRENOME = " << reg.sobrenome << endl;
   cout << "CURSO = " << reg.curso << endl;
   cout << "SEXO = " << reg.sexo << endl;
   cout << "DATA_NASCIMENTO = " << reg.dataNascimento << endl;
}

void colocaDadosNoRegistro(Registro *reg,char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]) {
   reg->cpf = cpf;
   reg->nome = nome;
   reg->sobrenome = sobrenome;
   reg->curso = curso;
   reg->sexo = sexo;
   reg->dataNascimento = dataNascimento;
}
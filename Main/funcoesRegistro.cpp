#include <cstring>
#include <iostream>
#include <stdio.h>
#include "funcoesBuffer.cpp"
#include "Registro.h"

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
      leStringDoBuffer(&buffer, reg->curso);
      leStringDoBuffer(&buffer, reg->sexo);
      leStringDoBuffer(&buffer, reg->dataNascimento);
      return true;
   } else {
      return false;
   }
}

void mostraRegistro(Registro reg) {
   cout << "CPF = " << reg.cpf << endl;
   cout << "NOME = " << reg.nome << endl;
   cout << "SOBRENOME = " << reg.sobrenome << endl;
   cout << "CURSO = " << reg.curso << endl;
   cout << "SEXO = " << reg.sexo << endl;
   cout << "DATA_NASCIMENTO = " << reg.dataNascimento << endl;
}

void colocaDadosNoRegistro(Registro *reg,char* cpf, char* nome, char* sobrenome, char* curso, char* sexo, char* dataNascimento) {
   reg->cpf = cpf;
   reg->nome = nome;
   reg->sobrenome = sobrenome;
   reg->curso = curso;
   reg->sexo = sexo;
   reg->dataNascimento = dataNascimento;
}

void imprimeFragmentacao(CabecalhoArqDados cad){
   if(cad.bytesUsados == 0){
      cout << "BYTES OCUPADOS: " << cad.bytesUsados << " BYTES LIVRES: " << 1000 << " FRAGMENTACAO: " << "0.00%" << endl;
   }else{
      cout << "BYTES OCUPADOS: " << cad.bytesUsados << " BYTES LIVRES: " << cad.bytesLivres << " FRAGMENTACAO: " << cad.bytesLivres * 100 / (cad.bytesUsados + cad.bytesLivres) << "%" << endl;
   }
}

void atualizaRegistro(/*Registro* reg, char* cpf, char* nome, char* sobrenome, char* curso, char* sexo, char* dataNascimento*/){
/*    
    reg->cpf = cpf;
    reg->nome = nome;
    reg->sobrenome = sobrenome;
    reg->curso = curso;
    reg->sexo = sexo;
    reg->dataNascimento = dataNascimento;*/
    cout << "REGISTRO ATUALIZADO COM SUCESSO" << endl;
}

void buscaRegistro(char * cpf){
   /*
   // Registro reg;
   // buscaArvoreB (raiz,cpf) 
   // busca dados no arquivo de dados (cpf)
   // reg <= dados do arquivo de dados
   if(cpf existe){
      atualizaRegistro(cpf);
   }else ...
   */
   cout << "REGISTRO NAO ENCONTRADO" << endl;
}

void inicializaListaVazia(listaBlocosVazios* listabv){
   listabv->cabeca = NULL;
}

void inicializaCabecalhoArqDados(CabecalhoArqDados* cad){
   cad->bytesLivres = 0;
   cad->bytesUsados = 0;
   cad->enderecoListaVazia = 0;
}

void gravaCpfNoArquivoDeIndice(char* cpf){
   arq = fopen("arquivoDeIndice.txt","a+");
   gravaString(cpf);
   gravaSeparador();
   fechaArq();
}

void gravaCabecalhoArqInd(CabecalhoArqIndice cai){
   arq = fopen("arquivoDeIndice.txt","a+");
   gravaInt(&(cai.enderecoRaizArvoreB));
   gravaSeparador();
   fechaArq();
}
/*
void gravaCabecalhoArqDados(ListaBlocosVazios lbv, CabecalhoArqDados cad){
   arq = fopen("arquivoDeDados.txt","a+");
   gravaBloco(listaVazia);
   gravaBloco(bytesUsados);
   gravaBloco(bytesLivres);
   fechaArq();
}*/
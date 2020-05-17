#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "funcoesAuxiliares.cpp"
#include "funcoesRegistro.cpp"
#include "funcoesArvoreB.cpp"

using namespace std;

int main(){
    
    Arv_B arvore;
    criaArvoreB(&arvore);

    CabecalhoArqDados cad;
    listaBlocosVazios listabv;
    inicializaListaVazia(&listabv);
    inicializaCabecalhoArqDados(&cad);
    // grava no arquivo de dados

    CabecalhoArqIndice cai;
    gravaCabecalhoArqInd(cai);

    char entrada[100] = {};
    char fechar[] = "FECHA";
    char insere[] = {"INSERE("};
    char busca[] = {"BUSCA"};
    char remove[] = {"REMOVE"};
    char atualiza[] = {"ATUALIZA"};
    char imprimeFrag[] = {"IMPRIME_FRAGMENTACAO"};

    char* cpf = (char*)malloc(sizeof(char)*10);
    char* nome = (char*)malloc(sizeof(char)*50);
    char* sobrenome = (char*)malloc(sizeof(char)*50);
    char* curso = (char*)malloc(sizeof(char)*50);
    char* sexo = (char*)malloc(sizeof(char)*2);
    char* dataNascimento = (char*)malloc(sizeof(char)*11);
    
    do {
        cin.getline (entrada,100);

        if(palavrasIguais(entrada, insere, 7)){
            // verifica se tem bloco disponivel ()
            salvaDadosInsere(entrada,100,cpf,nome,sobrenome,curso,sexo,dataNascimento);
            Registro registro;
            colocaDadosNoRegistro(&registro, cpf,nome,sobrenome,curso,sexo,dataNascimento);
            mostraRegistro(registro); // tirar isso aqui depois
            arq = fopen("arquivoDeDados.txt","a+");
            gravaRegistro(registro);
            printf("NOVO REGISTRO CRIADO COM SUCESSO\n");
            fechaArq();
            gravaCpfNoArquivoDeIndice(cpf);
            // aumenta o numero de bytes utilizados (syzeof(long long) + 50 + 50 + 50 + 1)

        }else if(palavrasIguais(entrada, busca, 5)){ 
            arq = fopen("arquivoDeDados.txt","r+");
            Registro reg;
            // buscaArvoreB (raiz,cpf) 
            // busca dados no arquivo de dados (cpf)
            // reg <= dados do arquivo de dados
            mostraRegistro(reg);
            fechaArq();

        }else if(palavrasIguais(entrada, remove, 6)){
            int cpf;
            removeRegistro(cpf);
            
        }else if(palavrasIguais(entrada, atualiza, 8)){
            atualizaRegistro();
            
        }else if(palavrasIguais(entrada, imprimeFrag, 20)){
            imprimeFragmentacao(cad);
            
        }else if(palavrasIguais(entrada, fechar, 5)){
            printf("ENCERRANDO\n");
        }
        else{
           printf("Entrada invalida\n");
        }

    } while(strcmp(entrada,fechar));

    return 0;
}
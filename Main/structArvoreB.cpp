#define b_tree_t 10
#include <iostream>
#include <stdlib.h>

typedef struct No {
    int nChaves;
    int* chave;
    No** c; //filho
    bool folha;
}No;

typedef struct Arv_B{
    No* raiz;
} Arv_B;

typedef struct No_Indice {
    No* x;
    int i; //i-esimo filho
}No_Indice;


void criaArvoreB(Arv_B* arvore);
No* alocaNo(bool folha);
No_Indice _No_Indice(No* x, int i);
No_Indice buscaEmArvoreB(No* x, int k);
void splitArvoreB(No* x, int i, No* y);
void insereNaArvoreB(Arv_B* arvore, int k);
void insereNaArvoreBnaoCheia(No* x, int k);
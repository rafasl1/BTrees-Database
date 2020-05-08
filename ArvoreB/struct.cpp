#define b_tree_t 10

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
#include "structArvoreB.cpp"

void criaArvoreB(Arv_B* arvore){
    No* x = alocaNo(true);
    // disk_write(x)
    arvore->raiz = x;
}

No* alocaNo(bool folha){
    No* x = (No*) malloc(sizeof(No));
    x->folha = folha;
    x->chave = (int*) malloc(sizeof(int) * (2*b_tree_t - 1));
    x->nChaves = 0;

    if(!folha){
        x->c = (No**) malloc (sizeof(No)*(2*b_tree_t));
    }
    return x;
}

No_Indice _No_Indice(No* x, int i){
    No_Indice ni;
    ni.x = x;
    ni.i = i;
    return ni;
}

No_Indice buscaEmArvoreB(No* x, int k){
    int i = 0;
    while(i < x->nChaves && k > x->chave[i]){
        i++;
    }
    if(i < x->nChaves && k == x->chave[i]){
        return _No_Indice(x,i);
    }
    if(x->folha){
        return _No_Indice(NULL,-1);
    }else{
        // disk_read(x->c[i])
        return buscaEmArvoreB(x->c[i],k);
    }
}

// y é o i-esimo filho de x
void splitArvoreB(No* x, int i, No* y){
    // cria o no z e copia a metade direita de y pra z
    No* z = alocaNo(y->folha);
    z->nChaves = b_tree_t - 1;

    // copia as chaves da metade direita de y pra z
    for(int j = 0; j < b_tree_t - 1; j++){
        z->chave[j] = y->chave[j + b_tree_t];
    }

    //se tiver filhos, copia os filhos da metade direita de y para z
    if(!y->folha){
        for(int j = 0; j < b_tree_t; j++){
            z->c[j] = y->c[j + b_tree_t];
        }
    }
    y->nChaves = b_tree_t - 1;

    /*
        faz um shift de uma posição em c[i+1..n] pra
        caber a mediana do no y que esta sendo dividido
    */
   for(int j = x->nChaves; j > i; j--){
       x->c[j+1] = x->c[j];
   }
   x->c[i+1] = z;

   for(int j = x->nChaves - 1; j >= i; j--){
       x->chave[j + 1] = x->chave[j];
   }

   x->chave[i] = y->chave[b_tree_t - 1]; // chave que foi promovida
   x->nChaves++;

   /* 
   disk write(x)
   disk write(y)
   disk write(z)
   */
}

void insereNaArvoreB(Arv_B* arvore, int k){
    No* r = arvore->raiz;

    if(r->nChaves == (2*b_tree_t - 1)){
        No* s = alocaNo(false);
        arvore->raiz = s;
        s->c[0] = r;
        splitArvoreB(s,0,r);
        insereNaArvoreBnaoCheia(s,k);
    }else{
        insereNaArvoreBnaoCheia(r,k);
    }
}

void insereNaArvoreBnaoCheia(No* x, int k){
    int i = x->nChaves-1;
    if(x->folha){
        while(x->folha){
            x->chave[i+1] = x->chave[i];
            i--;
        }

        x->chave[i+1] = k;
        x->nChaves++;
        //disk write x
    }else{
        while(i >= 0 && k < x->chave[i]){
            i--;
        }
        i++;
        // disk read x->c[i]

        if(x->c[i]->nChaves == 2*b_tree_t - 1){
            splitArvoreB(x,i,x->c[i]);

            if(k > x->chave[i]){
                i++;
            }
        }
        insereNaArvoreBnaoCheia(x->c[i], k);
    }
}
typedef struct Registro {
   char* cpf;
   char* nome;
   char* sobrenome;
   char* curso;
   char* sexo;
   char* dataNascimento;
} Registro;

struct Chave {
   int cpf;
   int enderecoProximoRegistro;
};

typedef struct CabecalhoArqIndice {
   int endereco;
};

typedef struct CabecalhoArqDados {
   int enderecoListaVazia;
   int bytesUsados;
   int bytesLivres;
};

typedef struct NoListaVazia {
   Registro * registro;
   NoListaVazia* prox;
} NoListaVazia;

typedef struct listaBlocosVazios {
   NoListaVazia* cabeca;
};


void gravaRegistro(Registro reg);
bool leProximoRegistro(Registro* reg);
void mostraRegistro(Registro reg);
void leLinhaStdin(char* s);
void colocaDadosNoRegistro(Registro *reg,char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]);

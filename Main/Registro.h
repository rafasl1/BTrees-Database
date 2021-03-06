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

struct CabecalhoArqIndice {
   int enderecoRaizArvoreB;
};

struct CabecalhoArqDados {
   int enderecoListaVazia;
   float bytesUsados;
   float bytesLivres;
};

typedef struct NoListaVazia {
   Registro * registro;
   NoListaVazia* prox;
} NoListaVazia;

struct listaBlocosVazios {
   NoListaVazia* cabeca;
};

void gravaRegistro(Registro reg);
bool leProximoRegistro(Registro* reg);
void mostraRegistro(Registro reg);
void leLinhaStdin(char* s);
void colocaDadosNoRegistro(Registro *reg,char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]);

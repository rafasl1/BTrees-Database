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
   int enderecoRegistro;
};

struct CabecalhoArqIndice {
   int endereco;
};

struct CabecalhoArqDados {
   int enderecoListaVazia;
   int bytesUsados;
   int bytesLivres;
};

void gravaRegistro(Registro reg);
bool leProximoRegistro(Registro* reg);
void mostraRegistro(Registro reg);
void leLinhaStdin(char* s);
void colocaDadosNoRegistro(Registro *reg,char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]);

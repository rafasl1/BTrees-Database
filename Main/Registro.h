typedef struct Registro {
   char* cpf;
   char* nome;
   char* sobrenome;
   char* curso;
   char* sexo;
   char* dataNascimento;
} Registro;

void gravaRegistro(Registro reg);
bool leProximoRegistro(Registro* reg);
void mostraRegistro(Registro reg);
void leLinhaStdin(char* s);
void colocaDadosNoRegistro(Registro *reg,char cpf[], char nome[], char sobrenome[], char curso[], char sexo[], char dataNascimento[]);

#define TAM_MAX_STRING 30

typedef struct Registro {
   int   id;
   char  nome[TAM_MAX_STRING];
   char  sobrenome[TAM_MAX_STRING];
} Registro;

void gravaRegistro(Registro reg);
bool leProximoRegistro(Registro* reg);
void mostraRegistro(Registro reg);
void leLinhaStdin(char* s);
Registro leRegistroStdin();

#define TAM_MAX_BUFFER 512
#define SEPARADOR_CHAR '|'

typedef struct Buffer {
   char registro[TAM_MAX_BUFFER];
   int prox;
} Buffer;

void gravaBloco(char* info, int tamBlocoEmBytes);
void gravaSeparador();
void gravaString(char* s);
void gravaInt(int* n);
Buffer leBloco(int tamBlocoEmBytes);
void leInt(int* n);
int leIntDoBuffer(Buffer* buffer);
void leStringDoBuffer(Buffer* buffer, char* s);
void abreArqEscrita(char* nomeArq);
void abreArqLeitura(char* nomeArq);
void fechaArq();
all: main.cpp Funcoes.cpp Buffer.o Registro.o ArvoreB.o
	g++ -o main main.cpp

Buffer.o : funcoesBuffer.cpp Buffer.h
	g++ -c funcoesBuffer.cpp

Registro.o : funcoesRegistro.cpp Registro.h
	g++ -c funcoesRegistro.cpp

ArvoreB.o : structArvoreB.cpp funcoesArvoreB.cpp
	g++ -c funcoesArvoreB.cpp
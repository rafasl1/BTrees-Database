all: main.cpp Funcoes.cpp Buffer.o Registro.o
	g++ -o main main.cpp

Buffer.o : funcoesBuffer.cpp Buffer.h
	g++ -c funcoesBuffer.cpp

Registro.o : funcoesRegistro.cpp Registro.h
	g++ -c funcoesRegistro.cpp
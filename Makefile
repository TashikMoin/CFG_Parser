CC = g++

all: CFG

CFG: Context_Free_Grammar.o
	$(CC) Context_Free_Grammar.o -o Context_Free_Grammar

Context_Free_Grammar.o: Context_Free_Grammar.cpp
	$(CC) -c Context_Free_Grammar.cpp

clean:
	rm -rf *o Context_Free_Grammar

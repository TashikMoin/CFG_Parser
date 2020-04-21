CC = g++

all: CFG

CFG: CFG-hassan.o
	$(CC) CFG-hassan.o -o CFG-hassan

CFG-hassan.o: CFG-hassan.cpp
	$(CC) -c CFG-hassan.cpp

clean:
	rm -rf *o CFG-hassan


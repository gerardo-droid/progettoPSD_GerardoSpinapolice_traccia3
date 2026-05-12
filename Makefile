# Definiamo il compilatore e i flag richiesti dal progetto (C99)
CC = gcc
CFLAGS = -Wall -std=c99 -g
OBJ = main.o //devi aggiungere il file delle funzioni

#TARGET PRINCIPALE 
programma.exe: $(OBJ)
	$(CC) $(OBJ) -o programma.exe

#Compilazione dei file .c e dei file .o	
main.o: main.c //inserisci file delle strutture.h e delle funzioni.h
	$(CC) $(CFLAGS) -c main.c

funzioni.o: funzioni.c funzioni.h strutture.h
	$(CC) $(CFLAGS) -c funzioni.c	

#Pulizia dei file temporanei
clean:
	del *.o programma.exe	

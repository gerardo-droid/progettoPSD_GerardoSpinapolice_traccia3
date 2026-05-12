# Definiamo il compilatore e i flag richiesti dal progetto (C99)
CC = gcc
CFLAGS = -Wall -std=c99 -g
OBJ = main.o segnalazioni.o

# TARGET PRINCIPALE
programma.exe: $(OBJ)
	$(CC) $(OBJ) -o programma.exe

# Compilazione dei file .c e dei file .o
main.o: main.c segnalazioni.h
	$(CC) $(CFLAGS) -c main.c

segnalazioni.o: segnalazioni.c segnalazioni.h
	$(CC) $(CFLAGS) -c segnalazioni.c

# Pulizia dei file temporanei
clean:
	rm -f *.o programma.exe
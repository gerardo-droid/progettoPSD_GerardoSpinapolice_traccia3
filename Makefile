# Definiamo il compilatore e i flag richiesti dal progetto (Standard C89)
CC = gcc
CFLAGS = -Wall -Wextra -std=c89 -pedantic

# L'eseguibile finale
TARGET = segnalazioni_comune

# Regola principale
all: $(TARGET)

# Come costruire l'eseguibile unendo i pezzi
$(TARGET): main.o segnalazioni.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o segnalazioni.o

# Come compilare il main
main.o: main.c segnalazioni.h
	$(CC) $(CFLAGS) -c main.c

# Come compilare la logica delle segnalazioni
segnalazioni.o: segnalazioni.c segnalazioni.h
	$(CC) $(CFLAGS) -c segnalazioni.c

# Comando per pulire i file temporanei
clean:
	rm -f *.o $(TARGET) *.exe
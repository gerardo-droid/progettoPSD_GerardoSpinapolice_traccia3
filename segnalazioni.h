#ifndef SEGNALAZIONI_H
#define SEGNALAZIONI_H

/* Definizione degli stati possibili della segnalazione */
typedef enum {
    APERTA,
    IN_CORSO,
    CHIUSA
} StatoSegnalazione;

/* Definizione del livello di urgenza */
typedef enum {
    BASSA,
    MEDIA,
    ALTA,
    CRITICA
} LivelloUrgenza;

/* Definizione della struttura principale della segnalazione */
typedef struct Segnalazione {
    int codice_id;                  /* codice identificativo */
    char nome_cittadino[50];        /* nome del cittadino */
    char categoria[50];             /* es. "illuminazione", "buche" */
    char descrizione[255];          /* descrizione del problema */
    char data_inserimento[11];      /* formato "GG/MM/AAAA" */
    LivelloUrgenza urgenza;         /* livello di urgenza usando l'enum */
    StatoSegnalazione stato;        /* stato usando l'enum */
    
    struct Segnalazione* next;      /* Puntatore al nodo successivo nella lista */
} Segnalazione;

/* Definizione del tipo puntatore per la testa della lista */
typedef Segnalazione* ListaSegnalazioni;

#endif
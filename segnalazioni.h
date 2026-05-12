#ifndef SEGNALAZIONI_H
#define SEGNALAZIONI_H

/*stati della segnalazione*/
typedef enum {
    APERTA,
    IN_CORSO,
    CHIUSA
} StatoSegnalazione;

/*livello di urgenza*/
typedef enum {
    BASSA,
    MEDIA,
    ALTA
} LivelloUrgenza;

/*struttura della segnalazione*/
typedef struct Segnalazione {
    int codice_id;                  /*codice identificativo*/
    char nome_cittadino[50];        /*nome del cittadino*/
    char categoria[50];             /*categoria*/
    char descrizione[255];          /*descrizione problema*/
    char data_inserimento[11];      /*data*/
    LivelloUrgenza urgenza;         /*livello urgenza*/
    StatoSegnalazione stato;        /*stato segnalazione*/
    
    struct Segnalazione* next;     
} Segnalazione;

/*puntatore per la testa della lista*/
typedef Segnalazione* ListaSegnalazioni;

/*funzione per inserire una nuova segnalazione*/
void inserisci_segnalazione(ListaSegnalazioni* testa, Segnalazione* nuova_segnalazione);
/*funzione per visualizzare la segnalazione*/
void visualizza_segnalazioni(ListaSegnalazioni testa);
/* Prototipo per allocare una nuova segnalazione in memoria */
Segnalazione* crea_segnalazione(int codice, const char* nome, const char* cat, const char* descr, const char* data, LivelloUrgenza urg);
/* Funzione per cercare una segnalazione nella lista tramite il suo ID numerico */
Segnalazione* cerca_segnalazione(ListaSegnalazioni testa, int id_da_cercare);
/* Funzione per eliminare una segnalazione dalla memoria */
int elimina_segnalazione(ListaSegnalazioni* testa, int id_da_eliminare);

#endif
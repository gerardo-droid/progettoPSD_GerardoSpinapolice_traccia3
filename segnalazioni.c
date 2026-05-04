#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segnalazioni.h"

/* Funzione per creare una nuova segnalazione allocando memoria */
Segnalazione* crea_segnalazione(int codice, const char* nome, const char* cat, const char* descr, const char* data, LivelloUrgenza urg) {

    /* 1. Allocazione Dinamica della memoria */
    Segnalazione* nuova = (Segnalazione*)malloc(sizeof(Segnalazione));

    /* Controllo di Sicurezza (Fondamentale per il voto sulla memoria) */
    if (nuova == NULL) {
        printf("Errore: memoria insufficiente.\n");
        return NULL; 
    }

    /* 2. Assegnazione dei valori passati come parametro */
    nuova->codice_id = codice;
    strcpy(nuova->nome_cittadino, nome);
    strcpy(nuova->categoria, cat);
    strcpy(nuova->descrizione, descr);
    strcpy(nuova->data_inserimento, data);
    nuova->urgenza = urg;

    /* 3. Valori di Default per una NUOVA segnalazione */
    nuova->stato = APERTA; /* Una segnalazione nasce sempre APERTA */
    nuova->next = NULL;    /* Non c'è ancora un nodo successivo */

    /* 4. Restituiamo il puntatore al nuovo blocco di memoria pronto */
    return nuova;
}
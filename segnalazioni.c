#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segnalazioni.h"

/*funzione per creare una nuova segnalazione allocando memoria*/
Segnalazione* crea_segnalazione(int codice, const char* nome, const char* cat, const char* descr, const char* data, LivelloUrgenza urg) {

    /*allocazione dinamica della memoria*/
    Segnalazione* nuova = (Segnalazione*)malloc(sizeof(Segnalazione));

    /*controllo sulla memoria*/
    if (nuova == NULL) {
        printf("Errore: memoria insufficiente\n");
        return NULL; 
    }

    /*assegnazione dei valori passati come parametro*/
    nuova->codice_id = codice;
    strcpy(nuova->nome_cittadino, nome);
    strcpy(nuova->categoria, cat);
    strcpy(nuova->descrizione, descr);
    strcpy(nuova->data_inserimento, data);
    nuova->urgenza = urg;

    /*valori per una nuova segnalazione*/ 
    nuova->stato = APERTA; /*segnalazione APERTA*/
    nuova->next = NULL;    

    /*restituiamo il puntatore*/
    return nuova;
}

void inserisci_segnalazione(ListaSegnalazioni* testa, Segnalazione* nuova_segnalazione) {
    /*se la lista è completamente vuota:*/
    if (*testa == NULL) {
        *testa = nuova_segnalazione;
    } 
    /*allora la lista ha già delle segnalazioni e:*/
    else {
        /*creiamo un puntatore temporaneo per scorrere la lista*/
        Segnalazione* temp = *testa;

        /*scorriamo fin quando non arriviamo a quello che punta al null*/
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = nuova_segnalazione;
    }
}

void visualizza_segnalazioni(ListaSegnalazioni testa) {
    Segnalazione* temp = testa;
    
    /* Variabili d'appoggio per tradurre i numeri (enum) in testo leggibile */
    const char* stringa_stato = "";
    const char* stringa_urgenza = "";

    printf("\n       ELENCO SEGNALAZIONI:          \n");

    /* Controllo se la lista e' vuota */
    if (temp == NULL) {
        printf(" Nessuna segnalazione nel sistema\n");
        return; 
    }

    /* Scorriamo la lista e formattiamo l'output */
    while (temp != NULL) {
        
        /* Traduzione logica dello Stato (da numero a testo) */
        switch (temp->stato) {
            case APERTA: stringa_stato = "Aperta"; break;
            case IN_CORSO: stringa_stato = "In Corso"; break;
            case CHIUSA: stringa_stato = "Chiusa"; break;
        }

        /* Traduzione logica dell'Urgenza (da numero a testo) */
        switch (temp->urgenza) {
            case BASSA: stringa_urgenza = "Bassa"; break;
            case MEDIA: stringa_urgenza = "Media"; break;
            case ALTA: stringa_urgenza = "Alta"; break;
        }

        /* Stampa formattata in stile "Ticket del Comune" */
        printf("\n[Ticket #%d] - Stato: %s (Urgenza: %s)\n", temp->codice_id, stringa_stato, stringa_urgenza);
        printf("Cittadino:   %s\n", temp->nome_cittadino);
        printf("Categoria:   %s\n", temp->categoria);
        printf("Problema:    %s\n", temp->descrizione);
        printf("Data:        %s\n", temp->data_inserimento);
        printf("-----------------------------------\n");
        
        /* Passiamo al nodo successivo */
        temp = temp->next;
    }
}

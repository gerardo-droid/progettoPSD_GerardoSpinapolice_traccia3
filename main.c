#include <stdio.h>
#include <stdlib.h>
#include "segnalazioni.h"

void svuota_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int scelta = -1;
    
    ListaSegnalazioni lista_comune = NULL; 

    printf("Sistema Della Gestione Delle Segnalazioni Al Comune\n");

    do {
        printf("\nMenu Principale:\n");
        printf("1. Inserisci una nuova segnalazione\n");
        printf("2. Visualizza tutte le segnalazioni\n");
        printf("3. Ricerca una segnalazione\n");
        printf("0. Esci dal programma\n");
        printf("Scegli un'opzione: ");
        
        if (scanf("%d", &scelta) != 1) {
            printf("Errore: devi inserire un numero\n");
            svuota_buffer(); 
            scelta = -1;
            continue; 
        }
        svuota_buffer();

        /*gestione delle scelte dell'utente*/
        /* Gestione delle scelte dell'utente */
        switch (scelta) {
           case 1: {
            /* 1. PRIMA la dichiarazione (Regola C89) */
            Segnalazione* nuova = crea_segnalazione(101, "Mario Rossi", "Illuminazione", "Lampione rotto in Via Roma", "05/05/2026", ALTA);
            
            /* 2. DOPO il codice operativo (printf) */
            printf("\n--- Inserimento Nuova Segnalazione ---\n");
            
            if (nuova != NULL) {
                inserisci_segnalazione(&lista_comune, nuova);
                printf("Segnalazione inserita con successo!\n");
            }
            break;
            }
            case 2:
                /* Richiamiamo la funzione passando la testa della lista */
                visualizza_segnalazioni(lista_comune);
                break;
            case 3:
                printf("\nHai scelto di cercare una segnalazione. (Funzione in lavorazione)\n");
                break;
            case 0:
                printf("\nChiusura del sistema in corso...\n");
                break;
            default:
                printf("\nOpzione non valida. Riprova.\n");
        }
    } while (scelta != 0);

    return 0;
}
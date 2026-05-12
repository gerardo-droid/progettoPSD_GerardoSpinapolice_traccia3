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
        printf("4. Aggiorna stato di una segnalazione\n");
        printf("0. Esci dal programma\n");
        printf("Scegli un'opzione: ");
        
        if (scanf("%d", &scelta) != 1) {
            printf("Errore: devi inserire un numero\n");
            svuota_buffer(); 
            scelta = -1;
            continue; 
        }
        svuota_buffer();

        /* Gestione delle scelte dell'utente */
        switch (scelta) {
            case 1: {
                int id_input;
                char nome_input[50];
                char cat_input[30];
                char desc_input[200];
                char data_input[11];
                int urgenza_scelta;
                LivelloUrgenza urg_input;
                Segnalazione* nuova;

                printf("\n--- Inserimento Nuova Segnalazione ---\n");
                printf("Inserisci ID numerico: ");
                scanf("%d", &id_input);
                svuota_buffer();

                printf("Inserisci Nome e Cognome: ");
                scanf("%[^\n]", nome_input);
                svuota_buffer();

                printf("Categoria (es. Illuminazione, Rifiuti): ");
                scanf("%[^\n]", cat_input);
                svuota_buffer();

                printf("Descrizione del problema: ");
                scanf("%[^\n]", desc_input);
                svuota_buffer();

                printf("Data (gg/mm/aaaa): ");
                scanf("%s", data_input);
                svuota_buffer();

                printf("Urgenza (0:BASSA, 1:MEDIA, 2:ALTA): ");
                scanf("%d", &urgenza_scelta);
                urg_input = (LivelloUrgenza)urgenza_scelta;
                svuota_buffer();

                nuova = crea_segnalazione(id_input, nome_input, cat_input, desc_input, data_input, urg_input);
                
                if (nuova != NULL) {
                    inserisci_segnalazione(&lista_comune, nuova);
                    printf("\n>>> Segnalazione salvata con successo!\n");
                }
                break;
            }
            case 2:
                visualizza_segnalazioni(lista_comune);
                break;

            case 3: {
                int id_ricerca;
                Segnalazione* trovata;
                
                printf("\n--- Ricerca Segnalazione ---\n");
                printf("Inserisci l'ID da cercare: ");
                scanf("%d", &id_ricerca);
                svuota_buffer();
                
                trovata = cerca_segnalazione(lista_comune, id_ricerca);
                
                if (trovata != NULL) {
                    printf("\n>>> SEGNALAZIONE TROVATA <<<\n");
                    printf("ID: %d | Cittadino: %s\n", trovata->codice_id, trovata->nome_cittadino);
                    printf("Problema: %s\n", trovata->descrizione);
                } else {
                    printf("\n>>> ERRORE: ID %d non trovato.\n", id_ricerca);
                }
                break;
            }

            case 4: {
                int id_modifica;
                int nuovo_stato_int;
                Segnalazione* da_modificare;

                printf("\n--- Aggiornamento Stato Segnalazione ---\n");
                printf("Inserisci l'ID della segnalazione da aggiornare: ");
                scanf("%d", &id_modifica);
                svuota_buffer();

                da_modificare = cerca_segnalazione(lista_comune, id_modifica);

                if (da_modificare != NULL) {
                    printf("Segnalazione trovata: [%s] %s\n", da_modificare->categoria, da_modificare->descrizione);
                    printf("Seleziona il nuovo stato:\n");
                    printf("0: APERTA\n1: IN LAVORAZIONE\n2: CHIUSA\nScelta: ");
                    scanf("%d", &nuovo_stato_int);
                    svuota_buffer();

                    if (nuovo_stato_int >= 0 && nuovo_stato_int <= 2) {
                        da_modificare->stato = (StatoSegnalazione)nuovo_stato_int;
                        printf("\n>>> Stato aggiornato con successo!\n");
                    } else {
                        printf("\n>>> ERRORE: Stato non valido.\n");
                    }
                } else {
                    printf("\n>>> ERRORE: ID %d non trovato.\n", id_modifica);
                }
                break;
            }
            case 0:
                printf("\nChiusura del sistema in corso...\n");
                break;
            default:
                printf("\nOpzione non valida. Riprova.\n");
                break;
        }
    } while (scelta != 0);

    return 0;
}
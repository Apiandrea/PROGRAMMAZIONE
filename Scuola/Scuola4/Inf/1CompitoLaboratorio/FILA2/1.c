/*
a)Memorizzare i dati di un prodotto di un'azienda utilizzando la struttura dati adeguata.
Il prodotto ha i seguenti campi:
1)codice;
2)descrizione;
3)prezzo;
4)quantità.
Visualizzare i dati inseriti ed effettuare tutti i controlli necessari sull'input.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int codice;
	char descrizione[50];
    int prezzo;
    int quantita;
}prodotto;

prodotto RegistraProdotto(prodotto utente)
{
	printf("Inserisci i dati.");
	
	printf("\n\nInserisci il suo codice: ");
	scanf("%d", &utente.codice);
	
	printf("Inserisci la sua descrizione (Massimo 50 caratteri): ");
	scanf(" %50[^\n]", &utente.descrizione);
	
	printf("\nInserisci il prezzo: ");
    do
    {
        scanf("%d", &utente.prezzo);
    }while(utente.prezzo <= 0);

    printf("\nInserisci la quantita: ");
    do
    {
        scanf("%d", &utente.quantita);
    }while(utente.quantita <= 0);

	return utente;
}

void StampaProdotto(prodotto utente)
{
	printf("\n\n\nCodice: %d", utente.codice);
	printf("\nDescrizione: %s", utente.descrizione);
    printf("\nPrezzo: %d\nQuantita: %d", utente.prezzo, utente.quantita);
}

int main()
{
	prodotto utente;
	
	utente = RegistraProdotto(utente);
	
	StampaProdotto(utente);
}

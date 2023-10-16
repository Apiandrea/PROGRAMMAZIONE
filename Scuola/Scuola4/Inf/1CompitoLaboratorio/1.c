/*
a)Memorizzare i dati di un partecipante ad una gara campestre utilizzando la struttura dati adeguata.
Definire i seguenti campi:
1)numero di pettorale;
2)nome;
3)tempo impiegato espresso in ore, minuti e secondi.
Visualizzare i dati inseriti ed effettuare tutti i controlli necessari sull'input.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ore;
	int minuti;
	int secondi;
}tempo_impiegato;

typedef struct
{
	int n_pettorale;
	char nome[50];
	tempo_impiegato t_partecipante;
}partecipante;

partecipante RegistraPartecipante(partecipante utente)
{
	printf("Inserisci i dati del partecipante.");
	
	printf("\n\nInserisci il suo numero di pettorale: ");
	scanf("%d", &utente.n_pettorale);
	
	printf("Inserisci il suo nome (Massimo 50 caratteri): ");
	scanf("%s", &utente.nome);
	
	printf("\nInserisci il tempo impiegato (tempo limite: 3 ore).");
	
	do
	{
		printf("\n\nOre: ");
		scanf("%d", &utente.t_partecipante.ore);
	}while(utente.t_partecipante.ore < 0 || utente.t_partecipante.ore > 2);
	
	do
	{
		printf("Minuti: ");
		scanf("%d", &utente.t_partecipante.minuti);
	}while(utente.t_partecipante.minuti < 0 || utente.t_partecipante.minuti > 59);
	
	do
	{
		printf("Secondi: ");
		scanf("%d", &utente.t_partecipante.secondi);
	}while(utente.t_partecipante.secondi < 0 || utente.t_partecipante.secondi > 59);
	
	return utente;
}

void StampaPartecipante(partecipante utente)
{
	printf("\n\n\nNome partecipate: %s", utente.nome);
	printf("\nNumero pettorale: %d", utente.n_pettorale);
	printf("\nTempo impiegato: %d ore, %d minuti, %d secondi", utente.t_partecipante.ore, utente.t_partecipante.minuti, utente.t_partecipante.secondi);
}

int main()
{
	partecipante utente;
	
	utente = RegistraPartecipante(utente);
	
	StampaPartecipante(utente);
}

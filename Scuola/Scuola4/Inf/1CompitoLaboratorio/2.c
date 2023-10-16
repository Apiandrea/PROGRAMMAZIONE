/*
b) Completare l'applicazione in modo da permettere l'inserimento di più concorrenti e 
lo svolgimento delle seguenti operazioni:
1) inserimento dati di un concorrente;
2) visualizzazione di tutti i partecipanti presenti in archivio;
3) ricerca di un concorrente dato il numero di pettorale;
4) classifica finale.
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
	int n_pettorale; char nome[50];
	tempo_impiegato t_partecipante;
}partecipante;


int menu()
{
	int scelta;
	
	do
	{
		printf("\n[1] inserimento dati di un concorrente");
		printf("\n[2] visualizzazione di tutti i partecipanti presenti in archivio");
		printf("\n[3] ricerca di un concorrente dato il numero di pettorale");
		printf("\n[4] classifica finale");
		printf("\n\n[0] chiudi programma");
		
		printf("\n\nInserisci: ");
		scanf("%d", &scelta);
		
	}while(scelta < 0 || scelta > 4);
	
	return scelta;
}

void VisualizzaPartecipante(partecipante elenco[], int index)
{
	printf("\n\n\nNome partecipate: %s", elenco[index].nome);
	printf("\nNumero pettorale: %d", elenco[index].n_pettorale);
	printf("\nTempo impiegato: %d ore, %d minuti, %d secondi", elenco[index].t_partecipante.ore, elenco[index].t_partecipante.minuti, elenco[index].t_partecipante.secondi);
	
	printf("\n\n");
}

void VisualizzaTutti(partecipante elenco[], int size)
{
	int i = 0;
	for(i; i < size; i++)
	{
		VisualizzaPartecipante(elenco, i);
	}
}

void InserisciPartecipante(partecipante elenco[], int index)
{
	int i = 0;
	int r = 0;
	
	printf("Inserisci i dati del partecipante n.%d", index +1);
	
	do
	{
        r = 0;
		printf("\n\nInserisci il suo numero di pettorale: ");
		scanf(" %d", &elenco[index].n_pettorale);
	
		for(i; i < index; i++)
		{
			if(elenco[i].n_pettorale == elenco[index].n_pettorale)
			{
				r = 1;
				printf("\nNon puoi inserire due numeri pettorali uguali");	
			}
		}	
	}while(r == 1);
	
	
	printf("Inserisci il suo nome (Massimo 50 caratteri): ");
	scanf("%s", &elenco[index].nome);
	
	printf("\nInserisci il tempo impiegato (tempo limite: 3 ore).");
	
	do
	{
		printf("\n\nOre : ");
		scanf("%d", &elenco[index].t_partecipante.ore);
	}while(elenco[index].t_partecipante.ore < 0 || elenco[index].t_partecipante.ore > 2);
	
	do
	{
		printf("Minuti: ");
		scanf("%d", &elenco[index].t_partecipante.minuti);
	}while(elenco[index].t_partecipante.minuti < 0 || elenco[index].t_partecipante.minuti > 59);
	
	do
	{
		printf("Secondi: ");
		scanf("%d", &elenco[index].t_partecipante.secondi);
	}while(elenco[index].t_partecipante.secondi < 0 || elenco[index].t_partecipante.secondi > 59);
}

int CercaConcorrente(partecipante elenco[], int size, int n_pettorale_ricerca)
{
	int i = 0;
	for(i; i < size; i++)
	{
		if(n_pettorale_ricerca == elenco[i].n_pettorale)
			return i;
	}
	
	return -1;
}

void swap(partecipante *a, partecipante *b)
{
    partecipante tmp = *a;
    *a = *b;
    *b = tmp;
}

void ClassificaFinale(partecipante elenco[], int size)
{
    int iMin;
    int iMinSec;
    int iJSec;
    for(int i = 0; i < size-1; i++)
    {
        iMin = i;
        iMinSec = elenco[i].t_partecipante.secondi + (elenco[i].t_partecipante.minuti * 60) + (elenco[i].t_partecipante.ore * 3600);
        for(int j = i+1; j < size; j++)
        {
            iJSec = elenco[j].t_partecipante.secondi + (elenco[j].t_partecipante.minuti * 60) + (elenco[j].t_partecipante.ore * 3600);
            if(iMinSec > iJSec)
            {
                iMin = j;
            }
        }

        swap(&elenco[iMin], &elenco[i]);
    }
    VisualizzaTutti(elenco, size);
}

int main()
{
	partecipante elenco[30];
	int scelta;
	int size_corrente = 0;
	int n_pettorale_ricerca;
	int result_ricerca;
	
	do
	{
		scelta = menu();
		
		switch(scelta)
		{
			case 1:
				InserisciPartecipante(elenco, size_corrente);
				size_corrente++;
				break;
				
			case 2:
				VisualizzaTutti(elenco, size_corrente);
				break;
				
			case 3:
				printf("Inserisci il numero di pettorale: ");
				scanf("%d", &n_pettorale_ricerca);
				result_ricerca = CercaConcorrente(elenco, size_corrente, n_pettorale_ricerca);
				
				if(result_ricerca > -1)
				{
					printf("il partecipante con numero di pettorale %d esiste, il partecipante e' il n.%d", n_pettorale_ricerca, result_ricerca+1);
					VisualizzaPartecipante(elenco, result_ricerca);
				}	
				else
					printf("il partecipante con numero di pettorale %d non esiste", n_pettorale_ricerca);
					
				break;                                                                                
			
			case 4:
				ClassificaFinale(elenco, size_corrente);
				break;
				
			case 0:
				printf("Chiusura programma...");
				break;
		}
	}while(scelta != 0);
}

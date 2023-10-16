/*
b) Completare l'applicazione in modo da permettere l'inserimento di più articoli e 
lo svolgimento delle seguenti operazioni:
1) inserimento articoli;
2) modifica di un articolo;
3) cancellazione di un articolo;
4) ricerca di un articolo;
5) visualizzazione di tutti i campi degli articoli presenti in archivio
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

int menu()
{
	int scelta;
	
	do
	{
		printf("\n[1] inserisci articolo");
		printf("\n[2] modifica articollo");
		printf("\n[3] cancella articolo");
		printf("\n[4] ricerca articolo");
        printf("\n[5] visualizza articoli");

		printf("\n\n[0] chiudi programma");
		
		printf("\n\nInserisci: ");
		scanf("%d", &scelta);
		
	}while(scelta < 0 || scelta > 5);
	
	return scelta;
}

void VisualizzaProdotto(prodotto elenco[], int index)
{
    if(elenco[index].codice != -99)
    {
        printf("\n\n\nCodice prodotto: %d", elenco[index].codice);
        printf("\nDescrizione: %s", elenco[index].descrizione);
        printf("\nPrezzo: %d", elenco[index].prezzo);
        printf("\nQuantita: %d", elenco[index].quantita);
        printf("\n\n");

    }
}

void VisualizzaTutti(prodotto elenco[], int size)
{
	int i = 0;
	for(i; i < size; i++)
	{
		VisualizzaProdotto(elenco, i);
	}
}

void InserisciProdotto(prodotto elenco[], int index)
{
	int i = 0;
	int r = 0;
	
	printf("Inserisci i dati del prodotto ");
	
	do
	{
        r = 0;
		printf("\n\nInserisci il suo codice: ");
        do
        {
            scanf(" %d", &elenco[index].codice);
        }while(elenco[index].codice <= 0);
	
		for(i; i < index; i++)
		{
			if(elenco[i].codice == elenco[index].codice)
			{
				r = 1;
				printf("\nNon puoi inserire due codici uguali");	
			}
		}	
	}while(r == 1);
	
	
	printf("Inserisci la sua descrizione (Massimo 50 caratteri): ");
	scanf(" %50[^\n]", &elenco[index].descrizione);
	
	do
	{
		printf("\nPrezzo: ");
		scanf("%d", &elenco[index].prezzo);
	}while(elenco[index].prezzo <= 0);
	
	do
	{
		printf("\nQuantita: ");
		scanf("%d", &elenco[index].quantita);
	}while(elenco[index].quantita <= 0);
}

void CancellaProdotto(prodotto elenco[], int index)
{
    elenco[index].codice = -99;
}

int CercaProdotto(prodotto elenco[], int size, int codice)
{
	int i = 0;
	for(i; i < size; i++)
	{
		if(codice == elenco[i].codice)
			return i;
	}
	
	return -1;
}

void swap(prodotto *a, prodotto *b)
{
    prodotto tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
	prodotto elenco[30];
	int scelta;
	int size_corrente = 0;
	int codice;
	int result_ricerca;
	
	do
	{
		scelta = menu();
		
		switch(scelta)
		{
			case 1:
				InserisciProdotto(elenco, size_corrente);
				size_corrente++;
				break;
				
			case 3:
                printf("Inserisci il codice: ");
				scanf("%d", &codice);
				result_ricerca = CercaProdotto(elenco, size_corrente, codice);
				
				if(result_ricerca > -1)
				{
                    CancellaProdotto(elenco, result_ricerca);
				}	
				else
					printf("il prodotto con codice %d non esiste", codice);
					
				break;
				
			case 4:
				printf("Inserisci il codice: ");
				scanf("%d", &codice);
				result_ricerca = CercaProdotto(elenco, size_corrente, codice);
				
				if(result_ricerca > -1)
				{
					printf("il prodotto con codice: %d esiste", codice, result_ricerca+1);
					VisualizzaProdotto(elenco, result_ricerca);
				}	
				else
					printf("il prodotto con codice %d non esiste", codice);
					
				break;                                                                                
			
			case 2:
                printf("Inserisci il codice: ");
				scanf("%d", &codice);
				result_ricerca = CercaProdotto(elenco, size_corrente, codice);
				
				if(result_ricerca > -1)
				{
					InserisciProdotto(elenco, result_ricerca);
				}	
				else
					printf("il prodotto con codice %d non esiste", codice);
					
				break;
			
            case 5:
                VisualizzaTutti(elenco, size_corrente);
                break;

			case 0:
				printf("Chiusura programma...");
				break;
		}
	}while(scelta != 0);
}

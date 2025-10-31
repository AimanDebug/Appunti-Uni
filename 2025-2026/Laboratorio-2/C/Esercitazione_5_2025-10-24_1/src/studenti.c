#include "studenti.h"

void initLista (ListaStudente* lista)
{
	lista->radice = NULL;
}

bool listaVuota (ListaStudente lista)
{
	return lista.radice == NULL;
}

void aggiungiStudente (ListaStudente* lista, unsigend int matricola,
		       unsigned int eta)
{
	NodoStudente* nuovo = (NodoStudente*)malloc(sizeof(NodoStudente));
	
	if (nuovo == NULL)
	{
		printf("ERRORE: Allocazione NodoStudente fallita!\n");
		return;
	}

	initNodoStudente(nuovo, matricola, eta, NULL);

	if (listaVuota(*lista))
	{
		lista->radice = nuovo;
		return;
	}

	NodoStudente* padre = lista->radice;

	while (padre->prossimo != NULL)
		padre = padre->prossimo;

	padre->prossimo = nuovo;
}

void initStudente (Studente* studente, unsigned int matricola, unsigned int eta)
{
	studente->matricola = matricola;
	studente->eta = eta;
}

void initNodoStudente(NodoStudente* nodoStudente, unsigned int matricola,
		      unsigned int eta, NodoStudente* prossimo)
{
	initStudente(nodoStudente->studente);
	nodoStudente->prossimo = prossimo;
}

void stampaStudente(Studente studente)
{
	printf("Matricola: %d, Eta: %d", studente.matricola, studente.eta);
}

void stampaLista (ListaStudente lista)
{
	if (listaVuota(lista))
		return;

	NodoStudente corrente = lista.radice;

	do
	{
		stampaStudente(corrente.studente);
		printf("\n");
	} while (corrente.prossimo != NULL);
}

void ordinaLista (ListaStudente* lista)
{
	if (listaVuota(lista))
		return;
	
	
}

void liberaLista (ListaStudente* lista)
{
	if (listaVuota(*lista))
		return;

	NodoStudente* corrente = lista->radice;

	do
	{
		NodoStudente* daCancellare = corrente;
		corrente = corrente->next;
		free(daCancellare);
	} while (corrente != NULL);
}

ListaStudente* filtraLista(ListaStudente lista, bool (*predicato)(Studente))
{
	ListaStudente* nuova = (ListaStudente*)malloc(sizeof(ListaStudente));

	initLista(nuova);

	if (listaVuota(lista))
		return;

	NodoStudente* corrente = lista.radice;

	do
	{
		aggiungiStudente (nuova, corrente->studente.matricola,
		    corrente->studente.eta);

		corrente = corrente->prossimo;
	} while (corrente != NULL);

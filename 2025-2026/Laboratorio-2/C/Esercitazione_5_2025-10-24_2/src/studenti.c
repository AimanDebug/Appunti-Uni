#include "studenti.h"

void initListaStudenti (ListaStudenti* lista)
{
	lista->radice = NULL;
}

void initNodoStudente (NodoStudente* nodo, Studente* studente)
{
	nodo->studente = *studente;
	nodo->prossimo = NULL;
}

void inserisciStudente (ListaStudenti* lista, Studente* studente)
{
	NodoStudente* nuovo = (NodoStudente*)malloc(sizeof(NodoStudente));
	initNodoStudente(nuovo, studente);

	if (lista->radice == NULL)
	{
		lista->radice = nuovo;
		return;
	}

	NodoStudente* corrente = lista->radice;

	while (corrente->prossimo != NULL)
		corrente = corrente->prossimo;

	corrente->prossimo = nuovo;
}

Studente* trovaStudente(ListaStudenti lista, bool (*predicato)(Studente* studente))
{
	NodoStudente* current = lista.radice;

	while (current != NULL)
	{
		if (predicato(current))
			return current;

		current = current->prossimo;
	}

	return NULL;
}

void perOgniStudente (ListaStudenti lista, void (*operazione)(Studente* studente))
{
	NodoStudente* corrente = lista.radice;

	while (corrente != NULL)
	{
		operazione (&(corrente.studente));
		corrente = corrente.prossimo;
	}
}

void eliminaStudente (ListaStudenti* lista, bool (*predicato)(Studente* studente))
{
	if (lista->radice == NULL)
		return;

	NodoStudente* corrente = lista->radice;

	// Radice
	if (predicato (lista->radice))
		lista->radice

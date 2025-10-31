#include <stdlib.h>
#include <stdio.h>

typedef struct Studente
{
	unsigned int matricola;
	unsigned int eta;
} Studente;

typedef struct NodoStudente NodoStudente;

NodoStudente
{
	Studente studente;
	NodoStudente* prossimo;
}

typedef struct ListaStudente
{
	NodoStudente* radice;
}

void initLista (ListaStudente* lista);
bool listaVuota (ListaStudente lista);
void aggiungiStudente (ListaStudente* lista, unsigned int matricola,
		       unsigned int eta);
void initStudente (Studente* studente, unsinged int matricola, unsigned int eta);
void initNodoStudente (NodoStudente* nodoStudente, unsigned int matricola,
		       unsigned int eta, NodoStudente* prossimo);
void stampaStudente (Studente studente);
void stampaLista (ListaStudente lista);
void ordinaLista (ListaStudente* lista);
void liberaLista (ListaStudente* lista);
ListaStudente* filtraLista(ListaStudente lista, bool (*predicato)(Studente));

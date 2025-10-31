#ifndef STUDENTI_H
#define STUDENTI_H

#include <stdlib.h>
#include <stdio.h>

#define NUM_VOTI 5

typedef struct Studente
{
	unsigned int matricola;
	unsigned int eta;
	unsigned int voti[NUM_VOTI];
} Studente;

typedef struct NodoStudente NodoStudente;

NodoStudente
{
	Studente studente;
	NodoStudente* prossimo;
};

typedef struct ListaStudenti
{
	NodoStudente* radice;
} ListaStudenti;

// Init
void initListaStudenti(ListaStudenti* lista);
void initNodoStudente(NodoStudente* nodo, Studente* studente);

// Operazioni
void inserisciStudente(ListaStudenti* lista, Studente* studente); 
void stampaStudenti(ListaStudenti lista);
Studente* trovaStudente(ListaStudenti lista, bool (*predicato)(Studente* studente));
void perOgniStudente(ListaStudenti lista, void (*operazione)(Studente* studente));
void eliminaStudente(ListaStudenti* lista, bool (*predicato)(Studente* studente));

#endif

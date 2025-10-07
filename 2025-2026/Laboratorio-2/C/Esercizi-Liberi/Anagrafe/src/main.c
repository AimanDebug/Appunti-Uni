#include <stdio.h>

typedef enum 
{
	DIRIGENTE,
	QUADRO,
	OPERAIO,
	IMPIEGATO
} TipoDipendente;

typedef struct
{
	int id;
	int eta;
	float stipendio;
	TipoDipendente tipoDipendente;
} Dipendente;

void leggiDipendenti(int, int[]);
int stipendioMedio(int, int[]);
void stampaSottopagati(int, int[], float);

int main(void)
{
	#define N 2
	Dipendente dipendenti[N];

	leggiDipendenti(N, dipendenti);
	int stipendioMedio = stipendioMedio(N, dipendenti);
	stampaSottopagati(N, dipendenti, stipendioMedio);

	return 0;
}

leggiId(int, Dipendenti[]);
leggiEta(int, Dipendenti[]);
leggiStipendio(int, Dipendenti[]);
leggiTipoDipendente(int, Dipendenti[]);

void leggiDipendenti(int lunghezza, Dipendenti dipendenti[], )
{
	for (int i = 0; i < lunghezza; ++i)
      	{
      		printf("Dipendente %d:\n", i);
		
		dipendenti[i].id = leggiId(i, dipendenti);
		dipendenti[i].eta = leggiEta(i, dipendenti);
		dipendenti[i].stipendio = leggiStipendio(i, dipendenti);
		dipendenti[i].tipoDipendente = leggiTipoDipendente(i, dipendenti);

		printf("\n");
	}
}

int leggiId(int lunghezza, Dipendenti dipendenti[])
{
	bool valido = false;
	int id;

	do
	{
		printf("Id: ");
		scanf("%d", &id);
		
		for (int i = 0; i < lunghezza; ++i)
       			if (id != dipendenti[i].id)
       			{
       				valido = true;
       				break;
       			}
	} while (!valido);

	return id;
}

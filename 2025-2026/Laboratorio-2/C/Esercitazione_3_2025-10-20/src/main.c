#include <stdlib.h>
#include <stdio.h>

typedef int (*trasforma_fn)(int);

int somma_con_trasformazione (int* a, int dim, trasforma_fn trasforma);
int valore_assoluto (int x);
int quadrato (int x);

int main()
{
	int dimensione;

	printf("Inserire lunghezza dell'array: ");
	scanf("%d", &dimensione);

	int* numeri = (int*)malloc(sizeof(int) * dimensione);
	
	printf("Inserire elementi: ");

	for (int i = 0; i < dimensione; ++i)
		scanf("%d", &numeri[i]);

	printf("Risultato:\n\tAbs: %d\n\tSqr: %d\n", 
		somma_con_trasformazione(numeri, dimensione, valore_assoluto),
		somma_con_trasformazione(numeri, dimensione, quadrato));

	free(numeri);

	return 0;
}

int somma_con_trasformazione (int* a, int dim, trasforma_fn trasforma)
{
	int risultato = 0;
	
	for (int i = 0; i < dim; ++i)
		risultato += trasforma(a[i]);

	return risultato;
}

int valore_assoluto (int x)
{
	return abs(x);
}

int quadrato (int x)
{
	return x * x;
}

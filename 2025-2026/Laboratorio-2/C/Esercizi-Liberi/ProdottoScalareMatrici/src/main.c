#include <stdio.h>

void readN(const int* outN);
void readMatrices(size_t length, int* matrixA[], int* matrixB[]);
int scalarProduct(size_t length, int* matrixA[], int* matrixB[]);

int main(void)
{
	const int n;
	readN(&n);

	int* matrixA = malloc(n * n * sizeof(int));
	int* matrixB = malloc(n * n * sizeof(int));
	readMatrices(matrixA, matrixB);
	int result = scalarProduct(matrixA, matrixB);

	printf("The scalar product of the two matrices is: %d.\n", result);

	return 0;
}

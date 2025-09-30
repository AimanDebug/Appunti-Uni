#include <stdio.h>

void readVectors(size_t length, int outVector1[], int outVector2[]);
int scalar(size_t length, int vector1[], int vector2[]);

int main()
{
	const size_t vectorSize = 3;
	int vector1[vectorSize], vector2[vectorSize];

	readVectors(vectorSize, vector1, vector2);
	printf("Scalar: %d\n", scalar(vectorSize, vector1, vector2));

	return 0;
}

void readVectors(size_t length, int outVector1[], int outVector2[])
{
     // Read vector 
	printf("Please input the first vector's components (%d): ", length);
	
	for (int i = 0; i < length; ++i)
      {
      scanf("%d", &outVector1[i]);
	}

	printf("\nPlease input the second vector's components (%d): ", length);
	
	for (int i = 0; i < length; ++i)
      {
      	scanf("%d", &outVector2[i]);
	}

	printf("\n");
}

int scalar(size_t length, int vector1[], int vector2[])
{
	int sum = 0;

	for (int i = 0; i < length; ++i)
      	sum += vector1[i] * vector2[i];

	return sum;
}

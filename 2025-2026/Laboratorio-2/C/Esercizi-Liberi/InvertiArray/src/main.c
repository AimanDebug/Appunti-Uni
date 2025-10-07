#include <stdio.h>

int main(void)
{
	int pippo[10];

	for (int i = 0; i < 10; ++i)
      	{
		pippo[i] = i;
		printf("%d, ", i);
	}
	
	for (int i = 0; i < 10 / 2; ++i)
      	{
      		int temp = pippo[i];
      		pippo[i] = pippo[10 - i - 1];
		pippo[10 - i - 1] = temp;
	}

	printf("\n");

	for (int i = 0; i < 10; ++i)
      		printf("%d, ", pippo[i]);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE* iFile = fopen("./test.txt", "r");
	FILE* oFile = fopen("./test.out", "a");

	if (!iFile)
	{
		perror("Error could not open.");
		return 1;
	}

	while (

	
	fclose(iFile);
	fclose(oFile);
}

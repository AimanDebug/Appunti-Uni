#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE* iFile = fopen("./test.txt", "r");
	FILE* oFile = fopen("./test.out", "a");

	if (!iFile)
	{
		perror("Error could not open input file.");
		return 1;
	}

	if (!oFile)
	{
		perror("Error could not open output file.");
		return 1;
	}

	while (

	
	fclose(iFile);
	fclose(oFile);
}

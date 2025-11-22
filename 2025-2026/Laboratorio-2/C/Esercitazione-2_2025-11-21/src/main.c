#include <stdio.h>
#include <stdlib.h>

void normalize(char* s);

int main()
{
	size_t iStringLength = 10;
	char* iString = (char*)malloc(iStringLength + 1);
	fgets(iString, iStringLength + 1, stdin);

	printf("Input string: %s\n", iString);

	normalize(iString);

	printf("Output string: %s\n", iString);
	return 0;
}

void normalize(char* s)
{
	char* realS = s;

	while (isspace((unsingned char)realS[0]))	
		++realS;

	size_t realSLength = 0;

	while (!isspace((unsinged char)realS[0]) && realS[0] != '\0')
	{
		*realS = tolower((unsigned char)*realS);
		++realSLength;
	

}

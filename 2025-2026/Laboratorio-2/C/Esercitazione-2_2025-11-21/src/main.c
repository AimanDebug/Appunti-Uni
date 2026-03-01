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
	char* currentChar = s;

	while (isspace((unsingned char)(*currentChar))
		++currentChar;

	if (currentChar == '\0') // Empty string or just whitespaces
		return;

	enum State { SPACE, CHARACTER } state = CHARACTER;

	*(s++) = *(currentChar++);

	while (*s != '\0')
	{
		if (isspace((unsigned char)(*currentChar)))
			switch (state)
			{
			case SPACE: // Last char was a space
				++currentChar;
				break;
			default: // CHARACTER
				*(s++) = *(currentChar;

}

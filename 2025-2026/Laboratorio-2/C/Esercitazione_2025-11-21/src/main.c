#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mymemmove(void* destination, void* source, size_t count);

int main()
{
	char buffer[8];
	strcpy(buffer, "abcdefg");
	printf("Original string: %s.\n", buffer);
	mymemmove((void*)(buffer + 3), (void*)buffer, 4);
	printf("New string: %s.\n", buffer);
	return 0;
}

void mymemmove(void* destination, void* source, size_t count)
{
	char* dst = (char*)destination;
	char* src = (char*)source;

	if (dst < src + count)
		for (size_t i = 0; i < count; ++i)
			dst[count - 1 - i] = src[count - 1 - i];
	else
		for (size_t i = 0; i < count; ++i)
			dst[i] = src[i];
}


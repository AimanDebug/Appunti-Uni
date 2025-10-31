#include "list.h"

int main ()
{
	List list;
	init(&list);

	insert(3, list);
	insert(1, list);

	print(list);

	return 0;
}

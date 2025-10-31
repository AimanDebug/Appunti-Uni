#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(List* list)
{
	list->root = NULL;
}

void print(List list)
{
	if (list.root == NULL)
		return;

	ListNode* current = list.root;
	
	do
	{
		printf("%d\n", current->value);
		current = current->next;
	} while (current != NULL);
}

void insert(int x, List list)
{
	if (list.root == NULL)
	{
		list.root = (ListNode*)malloc(sizeof(ListNode));
		list.root->value = x;
		list.root->next = NULL;
		
		return;
	}

	ListNode* current = list.root;

	while (current->next != NULL)
		current = current->next;

	current->next = (ListNode*)malloc(sizeof(ListNode));
	current->next->value = x;
	current->next->next = NULL;
}

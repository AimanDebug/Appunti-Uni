#ifndef LIST_H
#define LIST_H

typedef struct ListNode ListNode;

struct ListNode
{
	int value;
	ListNode* next;
};

typedef struct
{
	ListNode* root;
} List;

void init(List* list);
void print(List list);
void insert(int x, List list);
void insertRic(int x, List list);
void delete(List list);

#endif

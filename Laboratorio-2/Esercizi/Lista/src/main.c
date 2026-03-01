#include <stdio.h>

typedef struct ListNode_t {
    int value;
    struct ListNode_t* next;
} ListNode;

void print (ListNode** list);
void insert(int element, ListNode** list);
void insertRic(int element, ListNode** list);
void delete(ListNode** list);

int main() {
    ListNode* list = NULL;
    int i = 0;

    while (1) {
        int input;
        printf("Insert element %d: ", i);
        scanf("%d", &input);

        if (input < 0)
            break;

        if (input % 2 == 0)
            insertRic(input, &list);
        else
            insert(input, &list);
    }

    print(&list);

    printf("Clearing list...\n");
    while (&list != NULL)
        delete(&list);

    print(&list);
}

void print (ListNode** list) {
    if (*list == NULL)
        return;

    ListNode* current = *list;

    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void insert (ListNode** list) {
    if (*list == NULL)

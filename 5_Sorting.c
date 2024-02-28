#include <stdio.h>
#include <stdlib.h>
#include "6H_SortHeader.c"

struct Node;

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 44;
    second->next = third;

    // Link third and fourth nodes
    third->data = 75;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 34;
    fourth->next = NULL;

    printf("LinkList Before Sorting:\n");
    linkedListTraversal(head);

    sorting(head);

    printf("LinkList After Sorting:\n");
    linkedListTraversal(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    // struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void ReverceTraversal(struct Node *ptr)
{
    // struct Node *ptr = fifth;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    
    struct Node *head;
    struct Node *first; 
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link head and first 
    head->data = 1;
    head->prev = NULL;
    head->next = first;

    // Link first and second 
    first->data = 2;
    first->prev = head;
    first->next = second;


    // Link second and third 
    second->data = 3;
    second->prev = first;
    second->next = third;

    // Link third and fourth 
    third->data = 4;
    third->prev = second;
    third->next = fourth;

    // Link fourth and fifth 
    fourth->data = 5;
    fourth->prev = third;
    fourth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 6;
    fifth->prev = fourth;
    fifth->next = NULL;

    printf("LinkList In Forward Order:\n");
    linkedListTraversal(head);

    printf("\nLinkList In Reverce Order:\n");
    ReverceTraversal(fifth);
    return 0;
}
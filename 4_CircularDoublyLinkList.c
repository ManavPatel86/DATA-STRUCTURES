#include <stdio.h>
#include <stdlib.h>
#include "4H_CircularDoublyLinkList_Header.c"

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
    head->data = 10;
    head->prev = fifth;
    head->next = first;

    // Link first and second
    first->data = 2;
    first->prev = head;
    first->next = second;

    // Link second and third
    second->data = 23;
    second->prev = first;
    second->next = third;

    // Link third and fourth
    third->data = 4;
    third->prev = second;
    third->next = fourth;

    // Link fourth and fifth
    fourth->data = 53;
    fourth->prev = third;
    fourth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 6;
    fifth->prev = fourth;
    fifth->next = head;

    int x;
    printf("Enter \n1<To Print LinkList In Regular Order>\n");
    printf("2<To Print LinkList In Reverse Order>\n");
    printf("3<To Print Sorted LinkList>\n");
    printf("4<To Insert A New Node In The LinkList>: ");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        printf("LinkList In Forward Order:\n");
        linkedListTraversal(head);
        break;
    case 2:
        printf("\nLinkList In Reverce Order:\n");
        ReverceTraversal(fifth);
        break;
    case 3:
        printf("\nLinkList After Sorting:\n");
        sorting(head);
        linkedListTraversal(head);
        break;
    case 4:
        printf("\nLinkList After Insertion:\n");
        head = InsertByKey(head, 23, 10);
        linkedListTraversal(head);
        break;
    default:
        break;
    }

    printf("\n");
    head = deletnode(head, 4);
    linkedListTraversal(head);
    return 0;
}
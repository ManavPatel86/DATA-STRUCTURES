#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void ReverceTraversal(struct Node *fifth)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = fifth;

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    } while (ptr != fifth);
}

void sorting(struct Node *head)
{
    struct Node *str = head;
    struct Node *str2;

    while (str->next != head)
    {
        str2 = str->next;
        while (str2 != head)
        {
            if (str->data > str2->data)
            {
                int temp;
                temp = str2->data;
                str2->data = str->data;
                str->data = temp;
            }
            str2 = str2->next;
        }

        str = str->next;
    }
}

struct Node *InsertByKey(struct Node *head, int key, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *q = head->next;
    struct Node *p = head->next;

    while (p->data != key)
    {
        q = p->next;
        p = p->next;
    }
    q = p->next;
    p->next = ptr;
    ptr->next = q;
    return head;
}

struct Node *deletnode(struct Node *head, int x)
{

    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while (p->data != x)
    {
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
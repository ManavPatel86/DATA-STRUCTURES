#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void sorting(struct Node *head)
{
    struct Node *str = head;
    struct Node *str2;

    while (str != NULL)
    {
        str2 = str->next;
        while (str2 != NULL)
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

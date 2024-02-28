#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int IsFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int main()
{
    struct stack *s2;
    s2->size = 80;
    s2->top = -1;
    s2->arr = (int *)malloc(s2->size * sizeof(int));

    // Cheking Stack Is Empty Or Not
    if (IsEmpty(s2))
    {
        printf("The Stack Is Empty");
    }
    else
    {
        printf("The Stack Is Not Empty.");
    }
    return 0;
}
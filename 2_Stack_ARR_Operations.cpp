#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
};

/*...................Cheking Full Or Not...................*/
int IsFull(struct stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*...................Cheking Empy Or Not...................*/
int IsEmpty(struct stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*.......................Push() Function.......................*/
int push(struct stack *ptr, int val)
{
    if (IsFull(ptr))
    {
        cout << "Stack Is Overflow....!" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

/*.......................Pop() Function.......................*/
int pop(int *arr, int top)
{
    int temp;
    temp = arr[top];
    top -= 1;
    return temp;
}

/*..................Returning Top Value Of Stack..................*/
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

/*.................Returning Bottom Value Of Stack.................*/
int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}

/*.......................Display Function.......................*/
void displaystack(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << "Element-" << i << ": " << ptr->arr[i] << endl;
    }
}

int main()
{
    /*.......................Creating A Stack.......................*/
    struct stack *s1 = new struct stack[1];
    s1->size = 7;
    s1->top = -1;
    s1->arr = new int[s1->size];

    /*.......................Push() Operations.......................*/
    for (int i = 0; i < s1->size; i++)
    {
        int val;
        cout << "Enter The Value-" << i << ": ";
        cin >> val;
        push(s1, val);
    }

    cout << "\nStack Before Pop Operation...!" << endl;
    displaystack(s1);

    // cout << "\nTop Is: " << s1->top << endl;
    // cout << "\nThe Stack Is Full Or Not: " << IsFull(s1) << endl;
    // cout << "The Stack Is Empty Or Not: " << IsEmpty(s1) << endl;

    /*................Printing Top & Bottom Of Stack................*/
    cout << "\nTHE VALUE AT THE TOP IS: " << stacktop(s1) << endl;
    cout << "THE VALUE AT THE BOTTOM IS: " << stackbottom(s1) << endl;

    /*.......................Pop() Operations.......................*/
    cout << endl;
    if (IsEmpty(s1))
    {
        cout << "Stack Is Empty....!" << endl;
    }
    else
    {
        int temp = pop(s1->arr, s1->top);
        s1->top -= 1;
        cout << "The Poped Value From Top Is: " << temp << endl;

        temp = pop(s1->arr, s1->top);
        s1->top -= 1;
        cout << "The Poped Value From Top Is: " << temp << endl;

        temp = pop(s1->arr, s1->top);
        s1->top -= 1;
        cout << "The Poped Value From Top Is: " << temp << endl;
    }
    cout << "\nStack After Pop Operation...!" << endl;
    displaystack(s1);
    cout << endl;

    // cout << "Hello:- " << IsFull(s1) << endl;
    // cout << "Hello:- " << IsEmpty(s1) << endl;

    return 0;
}
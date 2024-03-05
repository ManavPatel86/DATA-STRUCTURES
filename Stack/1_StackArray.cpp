#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
};

void IsEmpty(int top)
{
    if (top < 0)
    {
        cout << "The Stack Is Empty..!" << endl;
    }
    else
    {
        cout << "The Stack Has Space." << endl;
    }
}

void IsFull(int top, int size)
{
    if (top >= size)
    {
        cout << "The Stack Is Full..!" << endl;
    }
    else
    {
        cout << "The Stack Has Space." << endl;
    }
}

int push(int *ptr, int top, int size)
{
    for (int i = 0; i < size; i++)
    {
        top++;
        int ele;
        cout << "Enter The Value Of E-" << top + 1 << ": ";
        cin >> ele;
        ptr[top] = ele;
    }
    return top;
}

void displaystack(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element-" << i + 1 << ": " << ptr[i] << endl;
    }
}

int main()
{
    struct stack s1;
    s1.size = 7;
    s1.top = -1;
    s1.arr = new int[s1.size];

    // IsEmpty(s1->top);
    // IsFull(s1->top, s1->top);

    if (s1.top == s1.size)
    {
        cout << "Stack Overflow...!" << endl;
    }
    else
    {
        s1.top = push(s1.arr, s1.top, s1.size);
        cout << "-----------O.U.T.P.U.T-----------" << endl;
        cout << "The Top Is: " << s1.top << endl;
    }

    cout << "-----------O.U.T.P.U.T-----------" << endl;
    displaystack(s1.arr, s1.size);
    return 0;
}
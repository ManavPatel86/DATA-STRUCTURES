#include <iostream>
using namespace std;

class stack1
{

    int *arr;
    int top;
    int size;

public:
    stack1(int SZ)
    {
        top = -1;
        size = SZ;
        arr = new int[size];
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack Is Full!" << endl;
            return;
        }
        else
        {
            top += 1;
            arr[top] = x;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No Element Can Be Pop!" << endl;
        }
        else
        {
            top -= 1;
        }
    }

    int Top(stack1 s)
    {
        if (top == -1)
        {
            cout << "Stack Is Empty!" << endl;
        }
        return s.arr[s.top];
    }
    void displaystack(stack1 s)
    {
        cout << "The elements in the stack are : ";
        for (int i = 0; i <= s.top; i++)
        {
            cout << s.arr[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{
    stack1 stk(7); // Create a Stack of Size 5

    // Push Element to the Stack
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);
    stk.push(70);

    stk.displaystack(stk);

    cout << "The Top Element Is: " << stk.Top(stk) << endl;

    stk.pop(); // Removing The Top Element From The Stack
    cout << "The Top Element Is: " << stk.Top(stk) << endl;

    stk.pop(); // Removing The Top Element From The Stack
    cout << "The Top Element Is: " << stk.Top(stk) << endl;

    stk.pop(); // Removing The Top Element From The Stack
    cout << "The Top Element Is: " << stk.Top(stk) << endl;

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

void insertatbottom(stack<int> &stk, int x)
{
    if (stk.empty())
    {
        stk.push(x);
        return;
    } // if stack is empty then push
    int topele = stk.top();
    stk.pop();
    insertatbottom(stk, x);
    stk.push(topele);
}
void reverse(stack<int> &stk)
{
    if (stk.empty())
    {
        // cout << "Reverse Not Possible As The  Stack Is Empty!" << endl;
        return;
    }
    int ele = stk.top();
    stk.pop();
    reverse(stk);
    insertatbottom(stk, ele);
}
int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    // cout << "Original Stack Elements Are : ";
    // while (stk.top()!=stk.size())
    // {
    //     cout << stk.top() << " ";
    //     stk.pop();
    // }

    cout << "\n\nReversed Stack Elements Are : ";
    reverse(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}

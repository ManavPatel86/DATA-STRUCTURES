#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> stk;
    string postfix;
    string infix;

    cout << "Enter the Infix Expression : ";
    getline(cin, infix);

    for (int i = 0; i < infix.length(); ++i)
    {
        if (infix[i] == '+' || infix[i] == '-')
        {
            if (!stk.empty())
            {
                if (stk.top() == '+' || stk.top() == '-' || stk.top() == '*' || stk.top() == '/' || stk.top() == '^')
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(infix[i]);
            }
            else
            {
                stk.push(infix[i]);
            }
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            if (!stk.empty())
            {
                if (stk.top() == '*' || stk.top() == '/' || stk.top() == '^')
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(infix[i]);
            }
            else
            {
                stk.push(infix[i]);
            }
        }
        else if (infix[i] == '^' || infix[i] == '$')
        {
            if (!stk.empty())
            {
                if (stk.top() == '^' || stk.top() == '$')
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(infix[i]);
            }
            else
            {
                stk.push(infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
        }
    }
    // Pop remaining operators from stack
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }

    cout << "PostFix Expressions: " << postfix << endl;

    return 0;
}
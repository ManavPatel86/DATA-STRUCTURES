#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^' || op == '$')
        return 3;
    return -1; // assuming -1 as lowest precedence
}

string infixToPostfix(string exp)
{
    stack<char> stk;
    string postfix;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (precedence(exp[i]) == 1)
        {
            if (!stk.empty())
            {
                if (precedence(exp[i]) <= precedence(stk.top()))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(exp[i]);
            }
            else
            {
                stk.push(exp[i]);
            }
        }
        else if (precedence(exp[i]) == 2)
        {
            if (!stk.empty())
            {
                if (precedence(exp[i]) <= precedence(stk.top()))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(exp[i]);
            }
            else
            {
                stk.push(exp[i]);
            }
        }
        else if (precedence(exp[i]) == 3)
        {
            if (!stk.empty())
            {
                if (precedence(exp[i]) <= precedence(stk.top()))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(exp[i]);
            }
            else
            {
                stk.push(exp[i]);
            }
        }
        else
        {
            postfix += exp[i];
        }
    }
    // Pop remaining operators from stack
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }
}

int main()
{
    string infix;

    cout << "Enter the Infix Expression : ";
    getline(cin, infix);

    cout << "PostFix Expressions: " << infixToPostfix(infix) << endl;

    return 0;
}
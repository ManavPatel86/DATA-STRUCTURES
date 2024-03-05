// #include <iostream>
// #include <stack>
// #include <string>
// #include <algorithm>
// #include <iostream>
#include <bits/stdc++.h>

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

string InfixToPrefix(string str)
{
    reverse(str.begin(), str.end());

    string prefix = "";
    stack<char> stk;

    for (int i = 0; i < str.length(); i++)
    {
        if (isalnum(str[i]))
        {
            prefix += str[i];
        }
        else if (str[i] == ')')
        {
            stk.push(str[i]);
        }
        else if (str[i] == '(')
        {
            while (!stk.empty() && stk.top() != ')')
            {
                prefix += stk.top();
                stk.pop();
            }
            if (!stk.empty())
            {
                stk.pop();
            }
        }
        else
        {
            while (!stk.empty() && precedence(str[i]) <= precedence(stk.top()))
            {
                prefix += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
    }

    // Push the remaining elements in stack to prefix expression
    while (!stk.empty())
    {
        prefix += stk.top();
        stk.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Reverse the string as we build from right to left

    return prefix;
}

int main()
{
    stack<char> stkOp, stkBrac;
    string postfix;
    string infix;

    cout << "\nEnter the Infix Expression : ";
    getline(cin, infix);

    cout << "PreFix Expressions: " << InfixToPrefix(infix) << endl
         << endl;
    return 0;
}

/*
Infix Expression: (a-b/c)*(a/k-l)
Prefix Expression: *-a/bc-/akl
*/
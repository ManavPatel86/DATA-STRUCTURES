#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int PostFixValue(string str)
{
    stack<int> s; // Stack to store operands char
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            s.push(str[i] - '0'); /* ASCII Value Of '0'=48; So Subtracting
                                  '0' From The Char To Get The Number.*/
        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(op2 + op1);
                break;
            case '-':
                s.push(op2 - op1);
                break;
            case '*':
                s.push(op2 * op1);
                break;
            case '/':
                s.push(op2 / op1);
                break;
            default: // '^' or '$'
                s.push(pow(op2, op1));
            }
        }
    }
    return s.top();
}
int main()
{
    string str;
    cout << "Enter PostFix Expression: ";
    getline(cin, str);

    cout << "Result is: " << PostFixValue(str) << endl;

    return 0;
}

/*
Input: 12+34+-3^
Output: Result is: -64
*/

/*ANOTHER METHOD OR LOOP WE THAT CAN USE
 for (c : str)
    {
        if (isdigit(c))
            s.push(c - '0');      // ASCII Value Of '0'=48; So Subtracting
                                  '0' From The Char To Get The Number.
        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (c)
            {
            case '+':
                s.push(op2 + op1);
                break;
            case '-':
                s.push(op2 - op1);
                break;
            case '*':
                s.push(op2 * op1);
                break;
            case '/':
                s.push(op2 / op1);
                break;
            default: // '^' or '$'
                s.push(pow(op2, op1));
            }
        }
    }
*/
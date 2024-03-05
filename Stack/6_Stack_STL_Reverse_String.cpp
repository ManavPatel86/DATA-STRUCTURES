#include <iostream>
#include <stack>
using namespace std;

void reversesentence(string s)
{
    stack<string> stk;
    for (int i = 0; i < s.length(); i++)
    {
        string RvStr = "";
        while (s[i] != ' ' && i < s.length())
        {
            RvStr += s[i];
            i++;
        }
        stk.push(RvStr);
        //  if (i < s.length() && s[i] == ' ') {
        //     stk.push(" ");
        // }
        // push all characters of the word to the stack
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Enter The Sentence: ";
    getline(cin,str);
    
    reversesentence(str);
    return 0;
}
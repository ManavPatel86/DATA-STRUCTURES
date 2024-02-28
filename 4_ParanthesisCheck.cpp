#include <iostream>
#include <string>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

/*...................Cheking Emtpy Or Not...................*/
int IsEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*...................Cheking Full Or Not...................*/
int IsFull(struct node *top)
{
    struct node *p = new node;
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*.......................Push() Function.......................*/
struct node *push(struct node *Top, char x)
{
    if (IsFull(Top))
    {
        cout << "The Stack Is OverFlow!\n"
             << endl;
    }
    else
    {
        node *n = new node;
        n->data = x;
        n->next = Top;
        return n;
    }
}

/*.......................Pop() Function.......................*/
void pop(struct node **ptr)
{
    struct node *n = *ptr;
    *ptr = (*ptr)->next;
    free(n);
}

/*..................Returning Top Value Of Stack..................*/
char stktop(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return ptr->data;
    }
}

/*........Function To Check Is Expression Is True Or Not........*/
void validexpression(struct node *ptr)
{
    if (IsEmpty(ptr))
    {
        cout << "THE GIVEN EXPRESSION HAS "
             << "VALID PARANTHESIS....!\n"
             << endl;
    }
    else
    {
        cout << "THE GIVEN EXPRESSION HAS "
             << "INVALID PARANTHESIS....!\n"
             << endl;
    }
}

/*.......................Main() Function.......................*/
int main()
{

    node *top = NULL;
    string str;

    cout << "Enter The Expression: ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            top = push(top, str[i]);
        }
        else if (str[i] == ')') //|| str[i] == '}' || str[i] == ']'
        {
            if (IsEmpty(top))
            {
                cout << "THE GIVEN EXPRESSION HAS "
                     << "INVALID PARANTHESIS....!\n"
                     << endl;
                goto here;
            }
            else
            {
                if (stktop(top) == '(')
                {
                    pop(&top);
                }
                else
                {
                    cout << "THE GIVEN EXPRESSION HAS "
                         << "INVALID PARANTHESIS....!\n"
                         << endl;
                }
            }
        }
        else if (str[i] == '}')
        {
            if (IsEmpty(top))
            {
                cout << "THE GIVEN EXPRESSION HAS "
                     << "INVALID PARANTHESIS....!\n"
                     << endl;
                goto here;
            }
            else
            {
                if (stktop(top) == '{')
                {
                    pop(&top);
                }
                else
                {
                    cout << "THE GIVEN EXPRESSION HAS "
                         << "INVALID PARANTHESIS....!\n"
                         << endl;
                }
            }
        }
        else if (str[i] == ']')
        {
            if (IsEmpty(top))
            {
                cout << "THE GIVEN EXPRESSION HAS "
                     << "INVALID PARANTHESIS....!\n"
                     << endl;
                goto here;
            }
            else
            {
                if (stktop(top) == '[')
                {
                    pop(&top);
                }
                else
                {
                    cout << "THE GIVEN EXPRESSION HAS "
                         << "INVALID PARANTHESIS....!\n"
                         << endl;
                }
            }
        }
        else
        {
            continue;
        }
    }

    validexpression(top);

here:
    return 0;
}
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

/*...................Cheking Empy Or Not...................*/
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
struct node *push(struct node *Top, int x)
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
    cout << "\n---------------------"
         << "After Performing The Pop Fuction"
         << "---------------------" << endl;
    if (IsEmpty(*ptr))
    {
        cout << "The Stack Is UnderFlow!\n"
             << endl;
    }
    else
    {
        struct node *n = *ptr;
        *ptr = (*ptr)->next;
        int x = n->data;
        cout << "The Value Poped from The stack is: " << n->data << endl;
        free(n);
    }
}

/*..................Returning Top Value Of Stack..................*/
void stacktop(struct node *ptr)
{
    if (ptr == NULL)
    {
        cout << "Stack Is Empty." << endl;
    }
    else
    {
        cout << "The Top Most Value In Stack is: " << ptr->data << endl;
    }
}

/*.................Returning Bottom Value Of Stack.................*/
void stackbottom(struct node *pt)
{
    struct node *ptr = pt;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    cout << "The Bottom Most value In Stack Is: " << ptr->data << endl;
}

/*.............Returning Value Of Stack At Given Position.............*/
void peak(struct node *ptr, int x)
{
    for (int i = 0; i < x - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        cout << "The Value At Position-" << x << " is: " << ptr->data << endl;
    }
    else
    {
        cout << "The Given Position Is Invalid." << endl;
    }
}

/*.......................Display Function.......................*/
void displaystack(struct node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        cout << "Stack Element-" << i << ": " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    /*.......................Creating A Stack.......................*/
    node *top = NULL;

    pop(&top);
    stacktop(top);

    /*.......................Push() Operations.......................*/
    top = push(top, 11);
    top = push(top, 12);
    top = push(top, 13);
    top = push(top, 14);
    top = push(top, 15);
    top = push(top, 16);
    top = push(top, 17);

    cout << "\n---------------------"
         << "After Performing The Push Fuction"
         << "---------------------" << endl;
    cout << endl;
    stacktop(top);
    stackbottom(top);
    peak(top, 3);
    cout << endl;
    displaystack(top);

    /*.......................Pop() Operations.......................*/
    pop(&top);
    cout<<endl;
    stacktop(top);
    stackbottom(top);
    peak(top, 3);
    cout << endl;
    displaystack(top);

    return 0;
}
// .
// .
// .
// .
// .
// #include <iostream>
// using namespace std;

// struct node
// {
//     int data;
//     struct node *next;
// };

// node *top = NULL;

// int IsEmpty(struct node *top)
// {
//     if (top == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int IsFull(struct node *top)
// {
//     struct node *p = new node;
//     if (p == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// struct node *push(struct node *Top, int x)
// {
//     if (IsFull(Top))
//     {
//         cout << "Stack OverFlow...!\n"
//              << endl;
//     }
//     else
//     {
//         node *n = new node;
//         n->data = x;
//         n->next = Top;
//         return n;
//     }
// }

// void pop(struct node *ptr)
// {
//     cout << "\nAfter Performing The Pop Fuction." << endl;
//     if (IsEmpty(ptr))
//     {
//         cout << "The Stack Is UnderFlow\n"
//              << endl;
//     }
//     else
//     {
//         struct node *n = ptr;
//         top = ptr->next;
//         int x = n->data;
//         cout << "The Value Poped from The stack is: " << n->data << endl;
//         free(n);
//     }
// }

// void displaystack(struct node *ptr)
// {
//     int i = 1;
//     while (ptr != NULL)
//     {
//         cout << "Stack Element-" << i << ": " << ptr->data << endl;
//         ptr = ptr->next;
//         i++;
//     }
// }

// int main()
// {
//     pop(top);

//     top = push(top, 11);
//     top = push(top, 12);
//     top = push(top, 13);
//     top = push(top, 14);
//     top = push(top, 15);
//     top = push(top, 16);
//     top = push(top, 17);

//     cout << "\nAfter Performing The Push Fuction." << endl;
//     displaystack(top);

//     pop(top);
//     displaystack(top);

//     return 0;
// }
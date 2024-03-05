#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// My Method:-:-:-:-:-:-:-
// void linktravelsal(struct Node *head)
// {
//     struct Node *ptr = head;
//     int i = 1;
//     while (ptr->next != head)
//     {
//         cout << "Element " << i << ": " << ptr->data << endl;
//         ptr = ptr->next;
//         i++;
//     }
//     cout << "Element 5: " << ptr->data << endl
//          << endl;
// }

// Another Method:-:-:-:-:-:-:-:-:-:-
void linktravelsal(struct Node *head)
{
    struct Node *ptr = head;
    int i = 1;
    do
    {
        cout << "Element " << i << ": " << ptr->data << endl;
        ptr = ptr->next;
        i++;
    } while (ptr != head);
    cout << "\n";
}

/*Deleting The First Node(Head) Of The Link List.*/
struct Node *deletfirst(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    ptr = ptr->next;
    free(head);
    return (ptr);
}

/*Inseting The First Element At First Node.*/
struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point the 'p' pointer points at the last node.
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

/* Insert The Node After Node With Given Key(Data).*/
struct Node *InsertByKey(struct Node *head, int key, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *q = head->next;
    struct Node *p = head->next;

    while (p->data != key)
    {
        q = p->next;
        p = p->next;
    }
    q = p->next;
    p->next = ptr;
    ptr->next = q;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    head = (struct Node *)malloc(sizeof(struct Node));
    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    cout << "Enter Data for Head: ";
    cin >> head->data;
    head->next = N1;

    cout << "Enter Data for 1st Element: ";
    cin >> N1->data;
    N1->next = N2;

    cout << "Enter Data for 2nd Element: ";
    cin >> N2->data;
    N2->next = N3;

    cout << "Enter Data for 3th Element: ";
    cin >> N3->data;
    N3->next = N4;

    cout << "Enter Data for 4th Element: ";
    cin >> N4->data;
    N4->next = head;

    cout << "Link List Before Insertion: " << endl;
    linktravelsal(head);

CHECK1:
    cout << "Enter 1<To Insert Element At First>" << endl
         << "2<To Insert Element After Given Key>" << endl
         << "3<To Delet First Element Of Link List>" << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        head = InsertAtFirst(head, 7);
        cout << "Link List After Insertion: " << endl;
        linktravelsal(head);
        break;
    case 2:
        cout << "Enetr Number After Whom You Want To Insert Node: " << endl;
        int key;
        cin >> key;
        cout << "Also Enter The Number To That Node: " << endl;
        int data;
        cin >> data;
        head = InsertByKey(head, key, data);
        linktravelsal(head);
        break;
    case 3:
        head = deletfirst(head);
        linktravelsal(head);
        break;
    default:
        cout << "Enter A Valid Number..!";
        break;
        goto CHECK1;
    }
    return 0;
}
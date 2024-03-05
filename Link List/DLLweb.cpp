#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

int main()
{
    // Initialize nodes
    Node *head = nullptr;
    Node *one = nullptr;
    Node *two = nullptr;
    Node *three = nullptr;

    // Allocate memory
    one = new Node(1);
    two = new Node(2);
    three = new Node(3);

    // Connect nodes
    one->next = two;
    one->prev = nullptr;

    two->next = three;
    two->prev = one;

    three->next = nullptr;
    three->prev = two;

    // Save the address of the first node in the head
    head = one;

    // Print the linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up memory
    delete one;
    delete two;
    delete three;

    return 0;
}
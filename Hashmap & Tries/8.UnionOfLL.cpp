#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void append(Node*& head, int new_data)
{
    Node* new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    map<int, int> mapping;
    Node* temp = head1;
    while (temp != NULL)
    {
        mapping[temp->data]++;
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL)
    {
        mapping[temp->data]++;
        temp = temp->next;
    }
    Node* newHead = NULL;
    Node* tail = NULL;
    for (auto& i : mapping)
    {
        Node* newNode = new Node(i.first);
        if (newHead == NULL)
        {
            newHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return newHead;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Create first linked list: 10->20->30
    append(head1, 10);
    append(head1, 20);
    append(head1, 30);

    // Create second linked list: 20->40
    append(head2, 20);
    append(head2, 40);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* unionList = makeUnion(head1, head2);

    cout << "Union: ";
    printList(unionList);

    return 0;
}

#include <iostream>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int getLength(ListNode* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* middleNode(ListNode* head)
{
    int n = getLength(head);
    int position = (n/2)+1;
    while(position != 1)
    {
        head = head->next;
        position--;
    }
    return head;
}

void printList(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    //linked list: 10 -> 20 -> 30 -> 40 -> 50
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    cout << "Original List: ";
    printList(head);

    head = middleNode(head);

    cout << "Middle List: ";
    printList(head);

    return 0;
}

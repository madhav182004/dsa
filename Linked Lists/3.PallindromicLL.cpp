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

ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr != nullptr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool compareLists(ListNode* head, ListNode* head2)
{
    while(head2 != NULL)
    {
        if(head->val != head2->val)
        {
            return false;
        }
        else
        {
            head = head->next;
            head2 = head2->next;
        }
    }
    return true;
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
    //linked list: 10 -> 20 -> 30 -> 20 -> 10
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(10);

    cout << "Original List: ";
    printList(head);
    
    ListNode* midNode = middleNode(head);
    ListNode* head2 = reverseList(midNode);

    if(compareLists(head, head2))
    {
        cout<<"Pallindrome"<<endl;
    }
    else
    {
        cout<<"Not Pallindrome"<<endl;
    }

    return 0;
}

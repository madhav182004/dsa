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

ListNode* detectCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            break;
        }
    }
    if(fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    // linked list: 10 -> 20 -> 30 -> 20 -> 10
    // ListNode* head = new ListNode(10);
    // head->next = new ListNode(20);
    // head->next->next = new ListNode(30);
    // head->next->next->next = new ListNode(20);
    // head->next->next->next->next = new ListNode(10);
    ListNode* head = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* fourth = new ListNode(20);
    ListNode* fifth = new ListNode(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;

    ListNode* cycleStart = detectCycle(head);

    if (cycleStart != nullptr)
    {
        cout << "Cycle detected at node with value: "<< cycleStart->val << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    return 0;
}

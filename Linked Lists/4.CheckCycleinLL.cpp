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

bool hasCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}

int main() {
    //linked list: 10 -> 20 -> 30 -> 20 -> 10
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

    if(hasCycle(head))
    {
        cout<<"Has Cycle"<<endl;
    }
    else
    {
        cout<<"Does not have cycle"<<endl;
    }
    return 0;
}

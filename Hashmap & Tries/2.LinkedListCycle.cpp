#include<iostream>
#include<unordered_map>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_map<ListNode* , bool> m;
    ListNode* temp = head;
    while(temp!=NULL)
    {
        if(m.find(temp) != m.end())
        {
            return true;
        }
        else
        {
            m[temp] = true;
        }
        temp=temp->next;
    }
    return false;
}
int main()
{
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    cout << "Test 1: " << (hasCycle(head1) ? "Cycle" : "No Cycle") << endl;

    //List with cycle: 1 -> 2 -> 3 -> 4 -> (points back to 2)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    //Creating a cycle (4 -> 2)
    head2->next->next->next->next = head2->next;

    cout << "Test 2: " << (hasCycle(head2) ? "Cycle" : "No Cycle") << endl;

    return 0;
}
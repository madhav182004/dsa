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
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    if(getLength(head) < k)
    {
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = NULL;
    int pos = 0;
    while(pos < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }

    if(nextNode != NULL)
    {
        head->next = reverseKGroup(nextNode, k);
    }
    return prev;
}
int main()
{
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter linked list values: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = reverseKGroup(head, k);

    cout << "Reversed List: ";
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

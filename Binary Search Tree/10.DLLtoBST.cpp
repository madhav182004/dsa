#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};
void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
Node* convertDLLtoBST(Node* &head, int n)
{
    if(head == NULL || n<=0)
    {
        return NULL;
    }
    //LNR
    Node* leftSubtree = convertDLLtoBST(head, n/2);

    Node* root = head;
    root->left = leftSubtree;
    head = head->right;

    Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
    root->right = rightSubtree;
    return root;
}
int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->right = third;
    third->left = second;
    second->left = first;

    Node* head = first;
    //10<->20<->30
    Node* root = convertDLLtoBST(head, 3);
    levelOrder(root);
    return 0;
}
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
Node* insertToBST(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data > root->data)
    {
        root->right = insertToBST(root->right, data);
    }
    else
    {
        root->left = insertToBST(root->left, data);
    }
    return root;
}
void createBST(Node*& root)
{
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insertToBST(root, data);
        cin>>data;
    }
}
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
Node* lca(Node* root, Node* p, Node* q)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(p->data < root->data && q->data < root->data)
    {
        Node* leftAns = lca(root->left, p, q);
        return leftAns;
    }
    if(p->data > root->data && q->data > root->data)
    {
        Node* rightAns = lca(root->right, p, q);
        return rightAns;
    }
    return root;
}
int main()
{
    Node* root = NULL;
    createBST(root);
    levelOrder(root);
    int val;
    cout<<"Enter the value of p:"<<endl;
    cin>>val;
    Node* p = new Node(val);
    cout<<"Enter the value of q:"<<endl;
    cin>>val;
    Node* q = new Node(val);
    Node* ans = lca(root, p, q);
    cout<<"LCA: "<<ans->data<<endl;
    return 0;
}
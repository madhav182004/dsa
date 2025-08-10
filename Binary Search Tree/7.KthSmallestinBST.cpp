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
int kthSmallest(Node* root, int &k) //pass by reference
{
    if(root == NULL)
    {
        return -1;
    }
    int leftAns = kthSmallest(root->left, k);
    if(leftAns != -1)
    {
        return leftAns;
    }
    k--;
    if(k==0)
    {
        return root->data;
    }
    int rightAns = kthSmallest(root->right, k);
    return rightAns;
}
int main()
{
    Node* root = NULL;
    createBST(root);
    levelOrder(root);
    int k;
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    int ans = kthSmallest(root, k);
    cout<<"kth smallest element in BST is: "<<ans<<endl;
    return 0;
}
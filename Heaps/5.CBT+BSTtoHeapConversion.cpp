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
void storeInorder(Node* root, vector<int>& inorder)
{
    if(root == NULL)
    {
        return;
    }
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}
void replaceUsingPostOrder(Node* root, vector<int>& inorder, int& index)
{
    if(root == NULL)
    {
        return;
    }
    replaceUsingPostOrder(root->left, inorder, index);
    replaceUsingPostOrder(root->right, inorder, index);
    root->data = inorder[index];
    index++;
}
Node* convertBSTtoMaxHeap(Node* root)
{
    vector<int> inorder;
    storeInorder(root, inorder);
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}
int main()
{
    Node* root = NULL;
    createBST(root);
    levelOrder(root);
    convertBSTtoMaxHeap(root);
    levelOrder(root);
    return 0;
}
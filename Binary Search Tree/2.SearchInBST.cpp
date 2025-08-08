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
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool searchInBST(Node*& root, int target)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == target)
    {
        return true;
    }
    bool leftans = false;
    bool rightans = false;
    if(target > root->data)
    {
        leftans = searchInBST(root->right, target);
    }
    else
    {
        rightans = searchInBST(root->left, target);
    }
    return leftans || rightans;
}
int main()
{
    Node* root = NULL;
    createBST(root);
    inorder(root);
    cout<<endl<<"Enter the target: ";
    int target;
    cin>>target;
    bool ans = searchInBST(root, target);
    if(ans == true)
    {
        cout<< "Found" <<endl;
    }
    else
    {
        cout<< "Not found" <<endl;
    }
    return 0;
}
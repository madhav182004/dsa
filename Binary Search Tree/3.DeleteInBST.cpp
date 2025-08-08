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
Node* maxValue(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node* deleteInBST(Node*& root, int target)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == target)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else if(root->left != NULL && root->right != NULL)
        {
            Node* maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = deleteInBST(root->left, maxi->data);
            return root;
        }
    }
    else if(target < root->data)
    {
        root->left = deleteInBST(root->left, target);
    }
    else
    {
        root->right = deleteInBST(root->right, target);
    }
    return root;
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
int main()
{
    Node* root = NULL;
    createBST(root);
    levelOrder(root);
    cout<<endl<<"Enter the target: ";
    int target;
    cin>>target;
    root = deleteInBST(root, target);
    cout<<endl;
    levelOrder(root);
}
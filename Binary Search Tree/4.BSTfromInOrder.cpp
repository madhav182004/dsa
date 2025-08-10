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
Node* bstFromInorder(int inorder[], int s, int e)
{
    if(s > e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstFromInorder(inorder, s, mid-1);
    root->right = bstFromInorder(inorder, mid + 1, e);

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
    int inorder[]={10, 20, 30, 40, 50, 60, 70};
    Node* root = bstFromInorder(inorder, 0, 6);
    levelOrder(root);
    return 0;
}
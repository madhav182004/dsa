#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxLevelSum(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int level = 1, ansLevel = 1;
    long long maxSum = LLONG_MIN;
    while (!q.empty())
    {
        int sz = q.size();
        long long currSum = 0;
        for (int i=0;i<sz;i++)
        {
            TreeNode* node = q.front();
            q.pop();

            currSum += node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(currSum > maxSum)
        {
            maxSum = currSum;
            ansLevel = level;
        }
        level++;
    }
    return ansLevel;
}

TreeNode* buildTree(vector<int>& nodes)
{
    if(nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nodes.size())
    {
        TreeNode* curr = q.front();
        q.pop();

        if(nodes[i] != -1)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if(i < nodes.size() && nodes[i] != -1)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> nodes(n);
    cout << "Enter tree values (use -1 for null): ";
    for (int i=0;i<n;i++)
    {
        cin >> nodes[i];
    }
    TreeNode* root = buildTree(nodes);
    cout<<"Maximum Level Sum is at level: "<<maxLevelSum(root)<<endl;
    return 0;
}

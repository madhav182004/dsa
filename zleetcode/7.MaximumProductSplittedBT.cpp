#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
long long totalSum = 0;
long long maxProduct = 0;
long long getTotalSum(TreeNode* root)
{
    if(!root) return 0;
    return root->val + getTotalSum(root->left) + getTotalSum(root->right);
}

long long dfs(TreeNode* root)
    {
    if(!root) return 0;

    long long left = dfs(root->left);
    long long right = dfs(root->right);

    long long subSum = root->val + left + right;

    long long product = subSum * (totalSum - subSum);
    maxProduct = max(maxProduct, product);
    return subSum;
}

int maxProductSplit(TreeNode* root)
{
    totalSum = getTotalSum(root);
    dfs(root);
    return maxProduct % MOD;
}

TreeNode* buildTree(vector<int>& nodes)
{
    if(nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
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
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    cout << "Maximum Product: "
         << maxProductSplit(root) << endl;

    return 0;
}

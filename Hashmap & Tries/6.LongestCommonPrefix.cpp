#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char val)
        {
            this->value = val;
            for(int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
            this->isTerminal = false;
            this->childCount = 0;
        }
};
void insertWord(TrieNode* root, string word)
{
    if(word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL)
    {
        //present
        child = root->children[index];
    }
    else
    {
        //absent
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}
void findLCP(string& ans, TrieNode* root)
{
    if(root->isTerminal == true)
    {
        return;
    }
    TrieNode* child;
    if(root->childCount == 1)
    {
        for(int i=0;i<26;i++)
        {
            if(root->children[i] != NULL)
            {
                child = root->children[i];
            }
        }
        ans.push_back(child->value);
    }
    else
    {
        return;
    }
    findLCP(ans, child);
}
int main()
{
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    // insertWord(root, "com");
    // insertWord(root, "lover");
    // insertWord(root, "loved");
    // insertWord(root, "load");
    // insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    // insertWord(root, "lov");

    cout<<"Insertion Done"<<endl;
    string ans = "";
    findLCP(ans, root);
    cout<<ans<<endl;
    return 0;
}
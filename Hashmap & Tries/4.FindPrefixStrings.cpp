#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val)
        {
            this->value = val;
            for(int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};
void insertWord(TrieNode* root, string word)
{
    // cout<<"recieved word: "<<word<<" for insertion "<<endl;
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
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}
void storeString(TrieNode* root, vector<string>& ans, string& input, string& prefix)
{
    if(root->isTerminal == true)
    {
        ans.push_back(prefix + input);
    }
    for(int i=0;i<26;i++)
    {
        TrieNode* next = root->children[i];
        if(next != NULL)
        {
            input.push_back(i + 'a');
            storeString(next, ans, input, prefix);
            input.pop_back();//backtracking
        }
    }
}
void findPrefixString(TrieNode* root, string input, vector<string>& ans, string& prefix)
{
    if(input.length() == 0)
    {
        TrieNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }
    findPrefixString(child, input.substr(1), ans, prefix);
}
int main()
{
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "load");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "lov");

    cout<<"Insertion Done"<<endl;

    string input = "c";
    string prefix = input;
    vector<string> ans;

    findPrefixString(root, input, ans, prefix);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Trie {
public:
    char value;
    Trie* children[58];
    bool isTerminal;
    Trie(char val = '\0') {
        this->value = val;
        for(int i=0;i<58;i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
    void insertHelper(Trie* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        char ch = word[0];
        if (ch < 'A' || ch > 'z')
        {
            return;
        }
        int index = ch - 'A';
        Trie* child;
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new Trie(ch);
            root->children[index] = child;
        }
        insertHelper(child, word.substr(1));
    }
    void insert(string word) {
        insertHelper(this, word);
    }
    bool searchWord(Trie* root, string word, int i)
    {
        if(i == word.length())
        {
            return root->isTerminal;
        }
        char ch = word[i];
        if (ch < 'A' || ch > 'z')
        {
            return false;
        }
        int index = ch - 'A';
        Trie* child;
        if(root->children[index] != NULL)
        {
            return searchWord(root->children[index], word, i+1);
        }
        else if(islower(word[i]))
        {
            return searchWord(root, word, i+1);
        }
        return false;
    }
    bool search(string word) {
        return searchWord(this, word, 0);
    }
};
vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    Trie trie;
    trie.insert(pattern);
    for(auto query : queries)
    {
        ans.push_back(trie.search(query));
    }
    return ans;
}
int main()
{
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FB";

    vector<bool> ans = camelMatch(queries, pattern);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "\"" << (bool)ans[i] << "\"";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
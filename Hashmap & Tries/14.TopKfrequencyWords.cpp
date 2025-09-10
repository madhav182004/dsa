#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class comp
{
    public:
        bool operator()(pair<int, string>& a, pair<int, string>& b)
        {
            return a.first == b.first ? a.second < b.second : a.first > b.first; //min-heap
        }
};
class Trie {
public:
    char value;
    Trie* children[26];
    bool isTerminal;
    int freq;
    Trie(char val) {
        this->value = val;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->freq = 0;
    }
    void insertHelper(Trie* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = true;
            ++root->freq;
            return;
        }
        char ch = word[0];
        int index = ch - 'a';
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
    void traverseHelper(Trie* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->isTerminal)
        {
            if(pq.size() < k)
            {
                pq.push({root->freq, s});
            }
            else if(pq.size() == k && root->freq > pq.top().first)
            {
                pq.pop();
                pq.push({root->freq, s});
            }
        }
        for(int i=0;i<26;i++)
        {
            if(root->children[i])
            {
                s.push_back(i + 'a');
                traverseHelper(root->children[i], s, pq, k);
                s.pop_back();
            }
        }
    }
    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k)
    {
        string s;
        traverseHelper(this, s, pq, k);
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    Trie* trie = new Trie('-');
    vector<string> ans;
    for(auto word : words)
    {
        trie->insert(word);
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    trie->traverse(pq, k);
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.second);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    vector<string> ans = topKFrequent(words, k);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "\"" << ans[i] << "\"";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
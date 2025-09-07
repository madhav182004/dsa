#include<iostream>
#include<vector>
using namespace std;

class Trie {
public:
    char value;
    Trie* children[26];
    bool isTerminal;
    Trie(char val = '-') {
        this->value = val;
        for(int i=0;i<26;i++)
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
    //changed the logic of search to return the index of how many indexes have been matches, as soon as we get terminal node, we return i
    int searchWord(Trie* root, string word, int i)
    {
        if(root->isTerminal)
        {
            return i;
        }
        if (i == word.length())
        {
            return -1;
        }
        char ch = word[i];
        int index = ch - 'a';
        Trie* child;
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return -1;
        }
        int recAns = searchWord(child, word, i+1);
        return recAns;
    }
    int search(string word) {
        return searchWord(this, word, 0);
    }
};
string replaceWords(vector<string>& dictionary, string sentence) {
    string ans = "";
    Trie trie;
    //inserting dict in trie
    for(auto root:dictionary)
    {
        trie.insert(root);
    }
    //pick each word and find in trie whether it is available or not
    int s = 0;
    int e = 0;
    while(e < sentence.size())
    {
        if(sentence[e] == ' ' || e == sentence.size()-1)
        {
            int len = e == sentence.size()-1 ? sentence.size() : e-s;
            string word = sentence.substr(s, len);
            int trieMatchIndex = trie.search(word);
            ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
            if(sentence[e] == ' ')
            {
                ans += ' ';
            }
            s = e+1;
        }
        e++;
    }
    return ans;
}
int main()
{
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string result = replaceWords(dictionary, sentence);

    cout << result << endl;
    return 0;
}
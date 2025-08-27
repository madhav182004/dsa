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
void storeString(TrieNode* root, vector<string>& ans, string& input)
{
    if(root->isTerminal == true)
    {
        ans.push_back(input);
    }
    for(int i=0;i<26;i++)
    {
        TrieNode* next = root->children[i];
        if(next != NULL)
        {
            input.push_back(i + 'a');
            storeString(next, ans, input);
            input.pop_back();//backtracking
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode* root, string input)
{
    vector<vector<string>> output;
    TrieNode* prev = root;
    string temp="";

    for(int i=0;i<input.length();i++)
    {
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode* curr = prev->children[index];
        if(curr == NULL)
        {
            break;
        }
        else
        {
            vector<string> nicheKaAns;
            temp.push_back(lastChar);
            storeString(curr, nicheKaAns, temp);
            output.push_back(nicheKaAns);
            //imp
            prev = curr;
        }
    }
    return output;
}
int main()
{
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "lov");

    cout<<"Insertion Done"<<endl;
    vector<vector<string>> output = getSuggestions(root, "loa");
    for(int i=0;i<output.size();i++)
    {
        cout<<i<<" -> ";
        for(auto& s:output[i])
        {
            cout<<s<<", ";
        }
        cout<<endl;
    }

    return 0;
}
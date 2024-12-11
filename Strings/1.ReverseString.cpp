#include<iostream>
#include<vector>
#include<string>
using namespace std;

string reverseString(string& s)
{
    vector<string> words;
    string word;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            if(!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += s[i];
        }
    }
    if(!word.empty())
    {
        words.push_back(word);
        word.clear();
    }
    string result;
    for(int i=words.size()-1;i>=0;i--)
    {
        result += words[i];
        if(i>0)
        {
            result += ' ';
        }
    }
    return result;
}
int main()
{
    string s;
    cout << "Enter the string to reverse: ";
    getline(cin, s);
    string ans = reverseString(s);
    cout << "Reversed String: " << ans << endl;
    return 0;
}
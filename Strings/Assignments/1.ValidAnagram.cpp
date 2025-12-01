#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isAnagram(string& s, string& t)
{
    int freqTable[256] = {0};
    for(char ch:s)
    {
        freqTable[ch]++;
    }
    for(char ch:t)
    {
        freqTable[ch]--;
    }
    for(int i=0;i<256;i++)
    {
        if(freqTable[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s, t;
    cout << "Enter the string s: ";
    getline(cin, s);
    cout << "Enter the string t: ";
    getline(cin, t);
    if(isAnagram(s, t))
    {
        cout << "Valid Anagram Strings. " << endl;
    }
    else
    {
        cout << "Not valid anagram strings. " << endl;
    }
    return 0;
}
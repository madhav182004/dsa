#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool areAnagrams(string& s1, string& s2)
{
    unordered_map<char, int> freq;
    for(char ch: s1)
    {
        freq[ch]++;
    }
    for(auto ch: s2)
    {
        if(freq[ch] > 0)
        {
            freq[ch]--;
        }
        else
        {
            return false;
        }
        if(freq[ch] == 0)
        {
            freq.erase(ch);
        }
    }
    return freq.empty();
}
int main()
{
    string s1, s2;
    cout << "Enter the string s1: ";
    getline(cin, s1);
    cout << "Enter the string s2: ";
    getline(cin, s2);
    if(areAnagrams(s1, s2))
    {
        cout<<"Pairs are anagrams"<<endl;
    }
    else
    {
        cout<<"Pairs are not anagrams"<<endl;
    }
    return 0;
}
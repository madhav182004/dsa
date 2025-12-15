#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0};
    bool istcharsMapped[256] = {0};
    for(int i=0;i<s.size();i++)
    {
        if(hash[s[i]] == 0 && istcharsMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            istcharsMapped[t[i]] = true;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(char(hash[s[i]]) != t[i])
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
    if(isIsomorphic(s, t))
    {
        cout << "Isomorphic Strings. " << endl;
    }
    else
    {
        cout << "Non isomorphic strings. " << endl;
    }
    return 0;
}
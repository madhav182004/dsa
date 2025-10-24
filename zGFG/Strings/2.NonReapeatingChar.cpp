#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

char nonRepeatingChar(string& s)
{
    unordered_map<char, int> freq;
    for(char ch: s)
    {
        freq[ch]++;
    }
    for(char ch: s)
    {
        if(freq[ch] == 1)
        {
            return ch;
        }
    }
    return '$';
}
int main()
{
    string s;
    cout << "Enter the string s: ";
    getline(cin, s);
    char ch = nonRepeatingChar(s);
    cout<<"Output: "<<ch<<endl;
    return 0;
}
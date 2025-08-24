#include<iostream>
#include<unordered_map>
using namespace std;

void countChar(unordered_map<char, int>& m, string& s)
{
    for(char ch : s)
    {
        m[ch]++;
    }
}

int main()
{
    string s;
    getline(cin, s);
    unordered_map<char, int> m;
    countChar(m, s);
    for(auto i: m)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
    return 0;
}
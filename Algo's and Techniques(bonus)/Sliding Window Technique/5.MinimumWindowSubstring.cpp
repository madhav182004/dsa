#include<iostream>
#include<vector>
#include<string>
using namespace std;

string minWindow(string& s, string& t)
{
    int len1 = s.length();
    int len2 = t.length();
    int start = 0;
    if(len1 < len2)
    {
        return "";
    }
    int ansIndex = -1;
    int ansLen = INT_MAX;
    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;
    for(char ch:t)
    {
        tMap[ch]++;
    }
    int count = 0;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        sMap[ch]++;
        if(sMap[ch]<=tMap[ch])
        {
            count++;
        }
        if(count == len2)
        {
            while(sMap[s[start]] > tMap[s[start]])
            {
                sMap[s[start]]--;
                start++;
            }
            int windowLen = i-start+1;
            if(windowLen<ansLen)
            {
                ansLen = windowLen;
                ansIndex = start;
            }
        }
    }
    if(ansIndex == -1)
    {
        return "";
    }
    else
    {
        return s.substr(ansIndex, ansLen);
    }
}
int main()
{
    string s, t;
    cout << "Enter the string s: ";
    getline(cin, s);
    cout << "Enter the pattern string t: ";
    getline(cin, t);
    string ans = minWindow(s, t);
    cout << "Ans string: " << ans << endl;
    return 0;
}
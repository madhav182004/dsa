#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isVowel(char ch)
{
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'|| ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
}

string reverseOnlyVowels(string s)
{
    int l = 0;
    int h = s.size()-1;
    while(l<h)
    {
        if(isVowel(s[l]) && isVowel(s[h]))
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
        else if(!isVowel(s[l]))
        {
            l++;
        }
        else if(!isVowel(s[h]))
        {
            h--;
        }
    }
    return s;
}
int main()
{
    string s, ans;
    cout << "Enter the string s: ";
    getline(cin, s);
    ans = reverseOnlyVowels(s);
    cout << "Ans: " << ans << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string reverseOnlyLetters(string s)
{
    int l = 0;
    int h = s.size()-1;
    while(l<h)
    {
        if(isalpha(s[l]) && isalpha(s[h]))
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
        else if(!isalpha(s[l]))
        {
            l++;
        }
        else
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
    ans = reverseOnlyLetters(s);
    cout << "Ans: " << ans << endl;
    return 0;
}
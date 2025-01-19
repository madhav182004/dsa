#include<iostream>
using namespace std;

bool isMatch(string s, int si, string p, int pi)
{
    if(si == s.size() && pi == p.size())
    {
        return true;
    }

    if(si == s.size() && pi < p.size())
    {
        while(pi < p.size())
        {
            if(pi!='*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }

    if(s[si] == p[pi] || '?' == p[pi])
    {
        return isMatch(s, si+1, p, pi+1);
    }

    if(p[pi] == '*')
    {
        bool caseNull = isMatch(s, si, p, pi+1);

        bool caseOne = isMatch(s, si+1, p, pi);

        return caseNull || caseOne;
    }
    return false;
}
int main()
{
    string s, p;
    cout << "Enter the string: ";
    getline(cin, s);
    cout << "Enter the pattern string: ";
    getline(cin, p);
    bool ans = isMatch(s, 0, p, 0);
    cout << "Ans: " << ans << endl;
    return 0;
}
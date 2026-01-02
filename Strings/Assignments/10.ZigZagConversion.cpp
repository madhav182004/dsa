#include<iostream>
#include<vector>
#include<string>
using namespace std;

string convert(string s, int numRows)
{
    if(numRows == 1)
    {
        return s;
    }
    string ans;
    int jumps = 2*(numRows-1);
    for(int i=0;i<numRows;i++)
    {
        for(int j=i;j<s.size();j+=jumps)
        {
            ans+=s[j];
            if(i>0 && i<numRows-1 && (j+jumps - 2*i)<s.size())
            {
                ans+=s[j+jumps-2*i];
            }
        }
    }
    return ans;
}
int main()
{
    int numRows;
    string s, ans;
    cout << "Enter the string : ";
    getline(cin, s);
    cout << "Enter the numRows : ";
    cin>>numRows;
    ans = convert(s, numRows);
    cout << "Zig Zag Converted : " << ans << endl;
    return 0;
}
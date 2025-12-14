#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.empty())
    {
        return "";
    }
    string prefix = strs[0];
    for(int i=1;i<strs.size();i++)
    {
        while(strs[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.length()-1);
            if(prefix.empty())
            {
                return "";
            }
        }
    }
    return prefix;
}
int main()
{
    int n;
    string ans;
    cout << "Enter the size of array: ";
    cin>>n;
    vector<string> strs(n);
    cout << "Enter the strings of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    ans = longestCommonPrefix(strs);
    cout << "Ans: " << ans << endl;
    return 0;
}
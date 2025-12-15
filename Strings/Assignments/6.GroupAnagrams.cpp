#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> mp;
    for(string s:strs)
    {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto& pair:mp)
    {
        ans.push_back(pair.second);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin>>n;
    vector<string> strs(n);
    cout << "Enter the strings of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    vector<vector<string>> ans = groupAnagrams(strs);
    cout << "Ans: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

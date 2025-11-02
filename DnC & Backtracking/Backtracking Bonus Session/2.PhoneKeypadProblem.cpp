#include<iostream>
#include<vector>
#include<string>
using namespace std;

void letterCombinations(string mapping[],string output,int index,vector<string>& ans,string str)
{
    if(index >= str.length())
    {
        if(output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    string temp = mapping[str[index] - '0'];
    for(auto ch:temp)
    {
        output.push_back(ch);
        letterCombinations(mapping, output, index+1, ans, str);
        //backtracking
        output.pop_back();
    }
}
int main()
{
    string str;
    cout<<"Enter the digits: ";
    getline(cin, str);
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    int index = 0;
    vector<string> ans;
    letterCombinations(mapping, output, index, ans, str);
    cout<<"All Possible Letters are : "<<endl;
    for(auto s:ans)
    {
        cout<<s<<endl;
    }
    return 0;
}

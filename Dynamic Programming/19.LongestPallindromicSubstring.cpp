#include<iostream>
#include<vector>
#include<string>
using namespace std;

// bool isPallindrome(string& s, int start, int end)
// {
//     while(start < end)
//     {
//         if(s[start] != s[end])
//         {
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }
int maxLen = 1, start = 0;
// bool solveUsingRec(string& s, int i, int j)
// {
//     if(i>=j)
//     {
//         return true;
//     }
//     bool flag = false;
//     if(s[i] == s[j])
//     {
//         flag = solveUsingRec(s, i+1, j-1);
//     }
//     if(flag)
//     {
//         int currLen = j - i + 1;
//         if(currLen > maxLen)
//         {
//             maxLen = currLen;
//             start = i;
//         }
//     }
//     return flag;
// }
bool solveUsingMemo(string& s, int i, int j, vector<vector<bool>>& dp)
{
    if(i>=j)
    {
        return true;
    }
    if(dp[i][j] != false)
    {
        return dp[i][j];
    }
    bool flag = false;
    if(s[i] == s[j])
    {
        flag = solveUsingMemo(s, i+1, j-1, dp);
    }
    if(flag)
    {
        int currLen = j - i + 1;
        if(currLen > maxLen)
        {
            maxLen = currLen;
            start = i;
        }
    }
    dp[i][j] = flag;
    return dp[i][j];
}
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n+1, vector<bool> (n+1, false));
    // string ans = "";
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            // if(isPallindrome(s, i, j))
            // {
            //     string t = s.substr(i, j-i+1);
            //     ans = t.size() > ans.size() ? t : ans;
            // }
            bool t = solveUsingMemo(s, i, j, dp);
        }
    }
    return s.substr(start, maxLen);
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin>>s;
    string ans = longestPalindrome(s);
    cout<<"Output :" << ans;
    return 0;
}
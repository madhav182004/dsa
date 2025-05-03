#include<iostream>
#include<vector>
#include<string>
using namespace std;

// int solveUsingRec(string& s1, string& s2, int i, int j)
// {
//     int cost = 0;
//     if(i == s1.size() || j == s2.size()) //returning the ASCII sum of remaining char in str
//     {
//         for(int x=i;x<s1.size();x++)
//         {
//             cost += s1[x];
//         }
//         for(int x=j;x<s2.size();x++)
//         {
//             cost += s2[x];
//         }
//     }
//     else if(s1[i] == s2[j])
//     {
//         cost = solveUsingRec(s1, s2, i+1, j+1);
//     }
//     else
//     {
//         int cost1 = s1[i] + solveUsingRec(s1, s2, i+1, j);
//         int cost2 = s2[j] + solveUsingRec(s1, s2, i, j+1);
//         cost = min(cost1, cost2);
//     }
//     return cost;
// }
// int solveUsingMemo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
// {
//     int cost = 0;
//     if(dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     if(i == s1.size() || j == s2.size()) //returning the ASCII sum of remaining char in str
//     {
//         for(int x=i;x<s1.size();x++)
//         {
//             cost += s1[x];
//         }
//         for(int x=j;x<s2.size();x++)
//         {
//             cost += s2[x];
//         }
//     }
//     else if(s1[i] == s2[j])
//     {
//         cost = solveUsingMemo(s1, s2, i+1, j+1, dp);
//     }
//     else
//     {
//         int cost1 = s1[i] + solveUsingMemo(s1, s2, i+1, j, dp);
//         int cost2 = s2[j] + solveUsingMemo(s1, s2, i, j+1, dp);
//         cost = min(cost1, cost2);
//     }
//     dp[i][j] = cost;
//     return dp[i][j];
// }
int solveUsingTabulation(string& s1, string& s2)
{
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i=s1.size()-1; i>=0;i--)
    {
        dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
    }
    for(int j=s2.size()-1; j>=0;j--)
    {
        dp[s1.size()][j] = s2[j] + dp[s1.size()][j+1];
    }

    for(int i=s1.size()-1; i>=0; i--)
    {
        for(int j=s2.size()-1; j>=0; j--)
        {
            int cost = 0;
            if(s1[i] == s2[j])
            {
                cost = dp[i+1][j+1];
            }
            else
            {
                int cost1 = s1[i] + dp[i+1][j];
                int cost2 = s2[j] + dp[i][j+1];
                cost = min(cost1, cost2);
            }
            dp[i][j] = cost;
        }
    }
    return dp[0][0];
}
int main()
{
    string s1, s2;
    cout << "Enter the string 1: ";
    cin>>s1;
    cout << "Enter the string 2: ";
    cin>>s2;
    int ans = solveUsingTabulation(s1, s2);
    cout<<"Output :" << ans;
    return 0;
}
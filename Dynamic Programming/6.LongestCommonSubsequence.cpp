#include<iostream>
#include<vector>
using namespace std;

    // int solveUsingRec(string a, string b, int i, int j)
    // {
    //     if(i >= a.length())
    //     {
    //         return 0;
    //     }
    //     if(j >= b.length())
    //     {
    //         return 0;
    //     }
    //     int ans = 0;
    //     if(a[i] == b[j])
    //     {
    //         ans = 1 + solveUsingRec(a, b, i+1, j+1);
    //     }
    //     else
    //     {
    //         ans = 0 + max(solveUsingRec(a, b, i, j+1), solveUsingRec(a, b, i+1, j));
    //     }
    //     return ans;
    // }
    // int solveUsingMemo(string& a, string& b, int i, int j, vector<vector<int> >& dp)
    // {
    //     if(i >= a.length())
    //     {
    //         return 0;
    //     }
    //     if(j >= b.length())
    //     {
    //         return 0;
    //     }
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }
    //     if(a[i] == b[j])
    //     {
    //         dp[i][j] = 1 + solveUsingMemo(a, b, i+1, j+1, dp);
    //     }
    //     else
    //     {
    //         dp[i][j] = 0 + max(solveUsingMemo(a, b, i, j+1, dp), solveUsingMemo(a, b, i+1, j, dp));
    //     }
    //     return dp[i][j];
    // }
    // int solveUsingTabulation(string& a, string& b)
    // {
    //     vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
    //     // int alen = a.length();
    //     // int blen = b.length();
    //     // for(int i = 0; i<=alen;i++)
    //     // {
    //     //     dp[i][blen] = 0;
    //     // }
    //     // for(int i = 0; i<=blen;i++)
    //     // {
    //     //     dp[alen][i] = 0;
    //     // }
    //     for(int i = a.length()-1;i>=0;i--)
    //     {
    //         for(int j = b.length()-1;j>=0;j--)
    //         {
    //             if(a[i] == b[j])
    //             {
    //                 dp[i][j] = 1 + dp[i+1][j+1];
    //             }
    //             else
    //             {
    //                 dp[i][j] = 0 + max(dp[i][j+1], dp[i+1][j]);
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }
// int solveUsingTabulationSO(string& a, string& b)
// {
//     vector<int> curr(a.length()+1, 0); //column wise
//     vector<int> next(a.length()+1, 0);
//     for(int j = b.length()-1;j>=0;j--)
//     {
//         for(int i = a.length()-1;i>=0;i--)
//         {
//             if(a[i] == b[j])
//             {
//                 curr[i] = 1 + next[i+1];
//         }
//             else
//             {
//                 curr[i] = 0 + max(next[i], curr[i+1]);
//             }
//         }
//         next = curr;
//     }
//     return next[0];
// }
int solveUsingTabulationSOwithoutLoopReverse(string& a, string& b)
{
    vector<int> curr(b.length()+1, 0); //row wise
    vector<int> next(b.length()+1, 0);
    for(int i = a.length()-1;i>=0;i--)
    {
        for(int j = b.length()-1;j>=0;j--)
        {
            if(a[i] == b[j])
            {
                curr[j] = 1 + next[j+1];
        }
            else
            {
                curr[j] = 0 + max(next[j], curr[j+1]);
            }
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    string a, b;
    cout << "Enter str1 : ";
    getline(cin, a);
    cout << "Enter str2 : ";
    getline(cin, b);
    int ans = solveUsingTabulationSOwithoutLoopReverse(a, b);
    cout<<"The longest common subsequence is :" << ans;
    return 0;
}
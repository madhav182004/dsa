#include<iostream>
#include<vector>
using namespace std;

// int solveUsingRec(int n, int k, int target)
// {
//     if(target < 0)
//     {
//         return 0;
//     }
//     if(n==0 && target==0)
//     {
//         return 1;
//     }
//     if(n==0 && target!=0)
//     {
//         return 0;
//     }
//     if(n!=0 && target==0)
//     {
//         return 0;
//     }
//     int ans = 0;
//     int MOD = 1e9 + 7;
//     for(int i=1;i<=k;i++)
//     {
//         ans = (ans + solveUsingRec(n-1, k, target-i)) % MOD;
//     }
//     return ans;
// }
// int solveUsingMemo(int n, int k, int target,vector<vector<int> > &dp)
// {
//     if(target < 0)
//     {
//         return 0;
//     }
//     if(n==0 && target==0)
//     {
//         return 1;
//     }
//     if(n==0 && target!=0)
//     {
//         return 0;
//     }
//     if(n!=0 && target==0)
//     {
//         return 0;
//     }
//     if(dp[n][target] != -1)
//     {
//         return dp[n][target];
//     }
//     int ans = 0;
//     int MOD = 1e9 + 7;
//     for(int i=1;i<=k;i++)
//     {
//         ans = (ans + solveUsingMemo(n-1, k, target-i, dp)) % MOD;
//     }
//     dp[n][target] = ans;
//     return dp[n][target];
// }
// int solveUsingTabulation(int n, int k, int target)
// {
//     vector<vector<int> > dp(n+1, vector<int> (target+1, 0));
//     dp[0][0] = 1;

//     for(int nth=1;nth<=n;nth++)
//     {
//         for(int tar=1;tar<=target;tar++)
//         {
//             int ans = 0;
//             int MOD = 1e9 + 7;
//             for(int i=1;i<=k;i++)
//             {
//                 if(tar-i >= 0)
//                 {
//                     dp[nth][tar] = (dp[nth][tar] + dp[nth-1][tar-i]) % MOD;
//                 }
//             }
//         }
//     }
//     return dp[n][target];
// }
int solveUsingTabulationSO(int n, int k, int target)
{
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1;

    for(int nth=1;nth<=n;nth++)
    {
        for(int tar=1;tar<=target;tar++)
        {
            int ans = 0;
            int MOD = 1e9 + 7;
            for(int i=1;i<=k;i++)
            {
                if(tar-i >= 0)
                {
                    ans = (ans + prev[tar-i]) % MOD;
                }
            }
            curr[tar] = ans;
        }
        prev = curr;
    }
    return prev[target];
}
int numRollsToTarget(int n, int k, int target) {
    // vector<vector<int> > dp(n+1, vector<int> (target+1, -1));
    int ans = solveUsingTabulationSO(n, k, target);
    return ans;
}

int main()
{
    int n, k, target;
    cout << "Enter the number of dices : ";
    cin>>n;
    cout << "Enter the number of faces of dices : ";
    cin>>k;
    cout << "Enter the target : ";
    cin>>target;
    int ans = numRollsToTarget(n, k, target);
    cout<<"The no. of possible ways are: " << ans;
    return 0;
}
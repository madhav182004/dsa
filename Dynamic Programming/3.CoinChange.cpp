#include<iostream>
#include<vector>
using namespace std; 

    // int solve(vector<int>& coins, int amount){
    //     if(amount == 0)
    //     {
    //         return 0;
    //     }
    //     if(amount < 0)
    //     {
    //         return INT_MAX;
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0;i<coins.size();i++)
    //     {
    //         int coin = coins[i];
            
    //         if(coin<=amount)
    //         {
    //             int recAns = solve(coins, amount-coin);
    //             if(recAns != INT_MAX)
    //             {
    //                 int ans = 1 + recAns;
    //                 mini = min(mini, ans);
    //             }
    //         }
    //     }
    //     return mini;
    // }
    // int solveUsingMemo(vector<int>& coins, int amount, vector<int>& dp){
    //     if(amount == 0)
    //     {
    //         return 0;
    //     }
    //     if(amount < 0)
    //     {
    //         return INT_MAX;
    //     }
    //     if(dp[amount]!=-1)
    //     {
    //         return dp[amount];
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0;i<coins.size();i++)
    //     {
    //         int coin = coins[i];
                
    //         if(coin<=amount)
    //         {
    //             int recAns = solveUsingMemo(coins, amount-coin, dp);
    //             if(recAns != INT_MAX)
    //             {
    //                 int ans = 1 + recAns;
    //                 mini = min(mini, ans);
    //             }
    //         }
    //     }
    //     dp[amount] = mini;
    //     return dp[amount];
    // }
int solveUsingTabulation(vector<int>& coins, int amount)
{
    int n = amount;
    vector<int> dp(n+1, -1);

    dp[0] = 0;

    for(int value = 1; value<=amount; value++)
    {
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int coin = coins[i];
                    
            if(value - coin >= 0)
            {
                int recAns = dp[value - coin];
                if(recAns != INT_MAX)
                {
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount) {
    // int n = amount;
    // vector<int> dp(n+1, -1);
    int ans = solveUsingTabulation(coins, amount);
    if(ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int n, amount;
    cout << "Enter the number of coins : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the value of each coin: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout << "Enter the amount : ";
    cin>>amount;
    int ans = solveUsingTabulation(nums, amount);
    cout<<"The minimum no. of coins required :" << ans;
    return 0;
}
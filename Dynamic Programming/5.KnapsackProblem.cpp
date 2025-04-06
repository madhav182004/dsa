#include<iostream>
#include<vector>
using namespace std;

// int solveUsingRec(int capacity, int wt[], int profit[], int index, int n)
// {
//     // if(index == n-1)
//     // {
//     //     if(wt[index] <= capacity)
//     //     {
//     //         return profit[index];
//     //     }
//     //     else
//     //     {
//     //         return 0;
//     //     }
//     // }

//     if(index >= n)
//     {
//         return 0;
//     }

//     int include = 0;
//     if(wt[index] <= capacity)
//     {
//         include = profit[index] + solveUsingRec(capacity-wt[index], wt, profit, index+1, n);
//     }
//     int exlcude = 0 + solveUsingRec(capacity, wt, profit, index+1, n);
//     int ans = max(include, exlcude);
//     return ans;
// }

// int solveUsingMemo(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> >& dp)
// {
//     if(index >= n)
//     {
//         return 0;
//     }

//     if(dp[capacity][index] != -1)
//     {
//         return dp[capacity][index];
//     }

//     int include = 0;
//     if(wt[index] <= capacity)
//     {
//         include = profit[index] + solveUsingMemo(capacity-wt[index], wt, profit, index+1, n, dp);
//     }
//     int exlcude = 0 + solveUsingMemo(capacity, wt, profit, index+1, n, dp);
//     dp[capacity][index] = max(include, exlcude);
//     return dp[capacity][index];
// }

// int solveUsingTabulation(int capacity, int wt[], int profit[], int n)
// {
//     vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));

//     for(int row = 0;row<=capacity;row++)
//     {
//         dp[row][n] = 0;
//     }
    
//     for(int i = 0; i<=capacity;i++)
//     {
//         for(int j = n-1; j>=0; j--)
//         {
//             int include = 0;
//             if(wt[j] <= i)
//             {
//                 include = profit[j] + dp[i-wt[j]][j+1];
//             }
//             int exlcude = 0 + dp[i][j+1];
//             dp[i][j] = max(include, exlcude);
//         }
//     }
//     return dp[capacity][0];
// }

// int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n)
// {
//     vector<int> next(capacity+1, -1);
//     vector<int> curr(capacity+1, -1);

//     for(int row = 0;row<=capacity;row++)
//     {
//         next[row] = 0;
//     }
    
//     for(int j = n-1; j>=0; j--)
//     {
//         for(int i = 0; i<=capacity;i++)
//         {
//             int include = 0;
//             if(wt[j] <= i)
//             {
//                 include = profit[j] + next[i-wt[j]];
//             }
//             int exlcude = 0 + next[i];
//             curr[i] = max(include, exlcude);
//         }
//         next=curr;
//     }
//     return curr[capacity];
// }

int solveUsingTabulationSO2(int capacity, int wt[], int profit[], int n)
{
    vector<int> next(capacity+1, 0);
    
    for(int j = n-1; j>=0; j--)
    {
        for(int i = capacity; i>=0;i--)
        {
            int include = 0;
            if(wt[j] <= i)
            {
                include = profit[j] + next[i-wt[j]];
            }
            int exlcude = 0 + next[i];
            next[i] = max(include, exlcude);
        }
    }
    return next[capacity];
}

int main()
{
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    // int index = 0;
    int n = 3;

    // vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));

    int ans = solveUsingTabulationSO2(capacity, wt, profit, n);
    cout<<"Max Profit :"<<ans<<endl;

    return 0;
}
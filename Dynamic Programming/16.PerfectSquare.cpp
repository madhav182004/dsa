#include<iostream>
#include<vector>
using namespace std;

// int solveUsingRec(int n)
// {
//     //base case
//     if(n==0)
//     {
//         return 1;
//     }

//     if(n < 0)
//     {
//         return 0;
//     }

//     int ans = INT_MAX;
//     int i = 1;
//     int end = sqrt(n);
//     while(i <= end)
//     {
//         int perfectSquare = i*i;
//         int numberOfPerfectSquares = 1 + solveUsingRec(n - perfectSquare);
//         if(numberOfPerfectSquares < ans)
//         {
//             ans = numberOfPerfectSquares;
//         }
//         ++i;
//     }
//     return ans;
// }
// int solveUsingMemo(int n, vector<int>& dp)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     if(n<0)
//     {
//         return 0;
//     }
//     if(dp[n] != -1)
//     {
//         return dp[n];
//     }
//     int i = 1;
//     int ans = INT_MAX;
//     int end = sqrt(n);
//     while(i <= end)
//     {
//         int perfectSquare = i*i;
//         int numberOfPerfectSquares = 1 + solveUsingMemo(n - perfectSquare, dp);
//         if(numberOfPerfectSquares < ans)
//         {
//             ans = numberOfPerfectSquares;
//         }
//         ++i;
//     }
//     dp[n] = ans;
//     return dp[n];
// }
int solveUsingTabulation(int n)
{
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int j=1;j<=n;j++)
    {
        int i = 1;
        int ans = INT_MAX;
        int end = sqrt(j);
        while(i <= end)
        {
            int perfectSquare = i*i;
            int numberOfPerfectSquares = 1 + dp[j - perfectSquare];
            if(numberOfPerfectSquares < ans)
            {
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        dp[j] = ans;
    }
    return dp[n];
}
int numSquares(int n) {
    // vector<int> dp(n+1, -1);
    return solveUsingTabulation(n) - 1;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin>>n;
    int ans = numSquares(n);
    cout<<"The no. of perfect squares are: " << ans;
    return 0;
}
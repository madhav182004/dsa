#include<iostream>
using namespace std;
// int fib(int n, vector<int>& dp) //top-down approach(rec + memoization)
// {
//     if(n==0 || n==1)
//     {
//         return n;
//     }
//     if(dp[n] != -1)
//     {
//         return dp[n];
//     }
//     dp[n] = fib(n-1, dp) + fib(n-2, dp);
//     return dp[n];
// }
// int fib(int n) //bottom-up approach(tabulation)
// {
//     vector<int> dp(n+1, -1);
//     dp[0] = 0;
//     if(n==0)
//         return dp[0];
//     dp[1] = 1;
//     for(int i = 2;i<=n;i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n];
// }
int fib(int n) //space optimisation
{
    int prev = 0;
    if(n==0)
        return 0;
    int curr = 1;
    if(n==0)
        return 1;
    int ans;
    for(int i = 2;i<=n;i++)
    {
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    // vector<int> dp(n+1, -1);
    // int ans = fib(n, dp);
    int ans = fib(n);
    cout<<"Output: "<<ans<<endl;
}
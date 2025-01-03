#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& coins, int amount)
{
    if(amount == 0)
    {
        return 0;
    }
    if(amount < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int coin = coins[i];
        if(coin<=amount)
        {
            int recAns = solve(coins, amount-coin);
            if(recAns!=INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}
int coinChange(vector<int>& coins, int amount) {
    int ans = solve(coins, amount);
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
    vector<int> coins(n);
    cout<<"Enter the coins: ";
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout << "Enter the amount you want to make: ";
    cin>>amount;
    int ans = coinChange(coins, amount);
    cout<<"The minimum coins are :" << ans;
    return 0;
}
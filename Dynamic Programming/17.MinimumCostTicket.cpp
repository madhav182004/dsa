#include<iostream>
#include<vector>
using namespace std;

// int solveUsingRec(vector<int>& days, int index, vector<int>& costs)
// {
//     if(index >= days.size())
//     {
//         return 0;
//     }
//     int oneDay = costs[0] + solveUsingRec(days, index+1, costs);
//     int passEndDay = days[index] + 7 - 1;
//     int j = index;
//     while(j < days.size() && days[j] <= passEndDay)
//     {
//         j++;
//     }
//     int sevenDay = costs[1] + solveUsingRec(days, j , costs);

//     passEndDay = days[index] + 30 - 1;
//     j = index;
//     while(j < days.size() && days[j] <= passEndDay)
//     {
//         j++;
//     }

//     int thrityDay = costs[2] + solveUsingRec(days, j , costs);

//     return min(oneDay, min(sevenDay, thrityDay));
// }
// int solveUsingMemo(vector<int>& days, int index, vector<int>& costs, vector<int>& dp)
// {
//     if(index >= days.size())
//     {
//         return 0;
//     }
//     if(dp[index] != -1)
//     {
//         return dp[index];
//     }

//     int oneDay = costs[0] + solveUsingMemo(days, index + 1, costs, dp);

//     int passEndDay = days[index] + 7 - 1;
//     int j = index;
//     while(j < days.size() && days[j] <= passEndDay)
//     {
//         j++;
//     }
//     int sevenDay = costs[1] + solveUsingMemo(days, j, costs, dp);

//     passEndDay = days[index] + 30 - 1;
//     j = index;
//     while(j < days.size() && days[j] <= passEndDay)
//     {
//         j++;
//     }
//     int thirtyDay = costs[2] + solveUsingMemo(days, j, costs, dp);

//     dp[index] = min(oneDay, min(sevenDay, thirtyDay));
//     return dp[index];
// }
int solveUsingTabulation(vector<int>& days, vector<int>& costs)
{
    int n = days.size();
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--)
    {
        int oneDay = costs[0] + dp[i+1];

        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int sevenDay = costs[1] + dp[j];

        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int thirtyDay = costs[2] + dp[j];

        dp[i] = min(oneDay, min(sevenDay, thirtyDay));
    }
    return dp[0];
}
int main()
{
    int n, c=3;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> days(n);
    vector<int> costs(c);
    cout << "Enter the days you want to travel: ";
    for(int i=0;i<n;i++)
    {
        cin >> days[i];
    }
    cout << "Enter the cost for one day, seven days and thirty days passes respectively: ";
    for(int i=0;i<c;i++)
    {
        cin >> costs[i];
    }
    int ans = solveUsingTabulation(days, costs);
    cout << "The minimum cost of ticket will be: " << ans;
    return 0;
}
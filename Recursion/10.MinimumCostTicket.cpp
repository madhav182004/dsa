#include<iostream>
#include<vector>
using namespace std;

int minCostTicket(vector<int>& days, int i, vector<int>& costs)
{
    if(i >= days.size())
    {
        return 0;
    }

    int oneDay = costs[0] + minCostTicket(days, i + 1, costs);

    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j<days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int sevenDay = costs[1] + minCostTicket(days, j, costs);

    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j<days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int thirtyDay = costs[2] + minCostTicket(days, j, costs);

    return min(oneDay, min(sevenDay, thirtyDay));
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
    int ans = minCostTicket(days, 0, costs);
    cout << "The minimum cost of ticket will be: " << ans;
    return 0;
}
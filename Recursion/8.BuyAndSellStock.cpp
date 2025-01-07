#include<iostream>
#include<vector>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit)
{
    if(i == prices.size())
    {
        return;
    }
    
    if(prices[i] < minPrice)
    {
        minPrice = prices[i];
    }
    int todayProfit = prices[i] - minPrice;
    if(todayProfit > maxProfit)
    {
        maxProfit = todayProfit;
    }

    maxProfitFinder(prices, i+1, minPrice, maxProfit);
}
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}
int main()
{
    int n;
    cout << "Enter the number of days : ";
    cin>>n;
    vector<int> prices(n);
    cout<<"Enter the value of stock on each day: ";
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int ans = maxProfit(prices);
    cout<<"The maximum profit will be :" << ans;
    return 0;
}
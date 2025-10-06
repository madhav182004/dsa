#include<iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int> &arr)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    for(auto price:arr)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans;
    ans = maximumProfit(arr);
    cout<<"Max Profit: "<<ans<<endl;
    return 0;
}
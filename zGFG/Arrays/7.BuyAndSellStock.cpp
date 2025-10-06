#include<iostream>
#include<vector>
using namespace std;

// int maximumProfit(vector<int> &arr)
// {
//     int i = 0;
//     int j = 1;
//     int ans = 0;
//     int maxi = 0;
//     while(j<arr.size())
//     {
//         int diff = arr[j] - arr[i];
//         if(diff > maxi)
//         {
//             maxi = diff;
//             j++;
//         }
//         else
//         {
//             ans += maxi;
//             maxi = 0;
//             i=j;
//             j++;
//         }
//     }
//     ans += maxi;
//     return ans;
// }

int maximumProfit(vector<int> &arr)
{
    int profit = 0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] > arr[i-1])
        {
            profit += arr[i] - arr[i-1];
        }
    }
    return profit;
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
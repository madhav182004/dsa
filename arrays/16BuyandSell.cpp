#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &nums)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int i=0;i<nums.size();i++)
    {
        minPrice = min(minPrice, nums[i]);
        maxProfit = max(maxProfit, nums[i]-minPrice);
    }
    return maxProfit;
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans = maxProfit(nums);
    cout<<"The maximum sum of subarray is :" << ans;
    return 0;
}
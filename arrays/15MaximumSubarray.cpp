#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];

        if(sum>maxi)
        {
            maxi = sum;
        }

        if(sum<0)
        {
            sum = 0;
        }
    }
    return maxi;
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
    int ans = maxSubArray(nums);
    cout<<"The maximum sum of subarray is :" << ans;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int currSum = arr[0];
    int maxSum = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
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
    ans = maxSubarraySum(arr);
    cout<<"Max Subarray Sum: "<<ans<<endl;
    return 0;
}
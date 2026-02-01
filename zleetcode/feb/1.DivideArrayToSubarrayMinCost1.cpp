#include<iostream>
#include<vector>
using namespace std;

int minimumCost(vector<int>& nums)
{
    int n=nums.size();
    int ans=INT_MAX;
    int rightMin=nums[n-1];
    for(int i=n-2;i>=1;i--)
    {
        rightMin = min(rightMin, nums[i+1]);
        ans = min(ans, nums[0] + nums[i] + rightMin);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int> nums(n);
    if(n==0)
    {
        cout<<"Array is empty";
        return 0;
    }
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = minimumCost(nums);
    cout<<"Ans : "<< ans <<endl;
    return 0;
}
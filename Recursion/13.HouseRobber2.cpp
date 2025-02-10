#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums, int i, int n)
{
    if(i > n)
    {
        return 0;
    }

    int chori = nums[i] + solve(nums, i+2, n);

    int nachori = 0 + solve(nums, i+1, n);

    return max(chori, nachori);
}
int rob(vector<int>& nums)
{
    int n = nums.size();
    if(n == 1)
    {
        return nums[0];
    }
    int option1 = solve(nums, 0, n-2);
    int option2 = solve(nums, 1, n-1);
    return max(option1, option2);
}
int main()
{
    int n;
    cout << "Enter the number of houses : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the money in houses: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans = rob(nums);
    cout<<"The maximum money that can be robbed :" << ans;
    return 0;
}
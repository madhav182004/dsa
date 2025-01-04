#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums, int size, int index)
{
    if(index>=size)
    {
        return 0;
    }

    int chori = nums[index] + solve(nums, size, index+2);

    int nachori = 0 + solve(nums, size, index+1);

    return max(chori, nachori);
}
int rob(vector<int>& nums)
{
    int size = nums.size();
    int ans = solve(nums, size, 0);
    return ans;
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
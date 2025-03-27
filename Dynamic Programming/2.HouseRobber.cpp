#include<iostream>
#include<vector>
using namespace std;

//recursion
// int solve(vector<int>& nums, int index)
// {
//     if(index >= nums.size())
//     {
//         return 0;
//     }

//     int chori = nums[index] + solve(nums, index+2);

//     int nachori = 0 + solve(nums, index+1);

//     return max(chori, nachori);
// }
//memo
// int solveUsingMemo(vector<int>&nums, int index, vector<int>& dp)
// {
//     if(index >= nums.size())
//     {
//         return 0;
//     }

//     if(dp[index] != -1)
//     {
//         return dp[index];
//     }

//     int chori = nums[index] + solveUsingMemo(nums, index+2, dp);

//     int nachori = 0 + solveUsingMemo(nums, index+1, dp);

//     dp[index] = max(chori, nachori);
//     return dp[index];
// }
//tabulation
// int solveUsingTabulation(vector<int>& nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     dp[n-1] = nums[n-1];
//     for(int i=n-2;i>=0;i--)
//     {
//         int tempAns = 0;
//         if(i+2 < n)
//         {
//             tempAns = dp[i+2];
//         }
//         int chori = nums[i] + tempAns;
//         int nachori = 0 + dp[i+1];
//         dp[i] = max(chori, nachori);
//     }
//     return dp[0];
// }
//space optimization
int solveUsingTabulationSO(vector<int>& nums)
{
    int n = nums.size();
    int prev = nums[n-1];
    int next = 0;
    int curr = 0;
    for(int i=n-2;i>=0;i--)
    {
        int tempAns = 0;
        if(i+2 < n)
        {
            tempAns = next;
        }
        int chori = nums[i] + tempAns;
        int nachori = 0 + prev;
        curr = max(chori, nachori);

        next = prev;
        prev = curr;
    }
    return prev;
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
    int ans = solveUsingTabulationSO(nums);
    cout<<"The maximum money that can be robbed :" << ans;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

// bool solveUsingRec(vector<int>& nums, int index, int sum, int target)
// {
//     if(index >= nums.size())
//     {
//         return 0;
//     }
//     if(sum > target)
//     {
//         return 0;
//     }
//     if(sum == target)
//     {
//         return true;
//     }

//     bool include = solveUsingRec(nums, index+1, sum + nums[index], target);
//     bool exclude = solveUsingRec(nums, index+1, sum, target);

//     return include || exclude;
// }
// bool solveUsingMemo(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp)
// {
//     if(index >= nums.size())
//     {
//         return 0;
//     }
//     if(sum > target)
//     {
//         return 0;
//     }
//     if(sum == target)
//     {
//         return true;
//     }
//     if(dp[index][sum] != -1)
//     {
//         return dp[index][sum];
//     }

//     bool include = solveUsingMemo(nums, index+1, sum + nums[index], target, dp);
//     bool exclude = solveUsingMemo(nums, index+1, sum, target, dp);
//     dp[index][sum] = (include || exclude);

//     return dp[index][sum];
// }
// bool solveUsingTabulation(vector<int>& nums, int target)
// {
//     int n = nums.size();
//     vector<vector<int> > dp(n+2, vector<int>(target+1, 0));
//     for(int row = 0;row<=n;row++)
//     {
//         dp[row][target] = 1;
//     }
    
//     for(int ind=n-1;ind>=0;ind--)
//     {
//         for(int s=target;s>=0;s--)
//         {
//             bool include = 0;
//             if(s+nums[ind] <= target)
//             {
//                 include = dp[ind+1][s+nums[ind]];
//             }
//             bool exclude = dp[ind+1][s];
//             dp[ind][s] = (include || exclude);
//         }
//     }
//     return dp[0][0];
// }
bool solveUsingTabulationSO(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    curr[target] = 1;
    next[target] = 1;
    
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int s=target;s>=0;s--)
        {
            bool include = 0;
            if(s+nums[ind] <= target)
            {
                include = next[s+nums[ind]];
            }
            bool exclude = next[s];
            curr[s] = (include || exclude);
        }
        next = curr;
    }
    return next[0];
}
bool canPartition(vector<int>& nums) {
    // int index = 0;
    int totalSum = 0;
    for(int i=0;i<nums.size();i++)
    {
        totalSum+=nums[i]; 
    }
    if(totalSum & 1) //if odd
    {
        return false;
    }
    int target = totalSum/2;
    // int currSum = 0;
    // vector<vector<int> > dp(nums.size()+1, vector<int>(target+1, -1));
    bool ans = solveUsingTabulationSO(nums, target);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of nums : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the values of nums: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    bool ans = canPartition(nums);
    cout << "Output : " << boolalpha << ans << endl;
    return 0;
}
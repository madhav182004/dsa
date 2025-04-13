#include<iostream>
#include<vector>
using namespace std;

    // int solveUsingRec(vector<int>& nums, int curr, int prev)
    // {
    //     if(curr >= nums.size())
    //     {
    //         return 0;
    //     }

    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev])
    //     {
    //         include = 1+solveUsingRec(nums, curr+1, curr);
    //     }
    //     int exclude = 0+solveUsingRec(nums, curr+1, prev);

    //     int ans = max(include, exclude);
    //     return ans;
    // }
    // int solveUsingMemo(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp)
    // {
    //     if(curr >= nums.size())
    //     {
    //         return 0;
    //     }
    //     //index shifting becuase prev = -1
    //     if(dp[curr][prev+1] != -1)
    //     {
    //         return dp[curr][prev+1];
    //     }

    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev])
    //     {
    //         include = 1+solveUsingMemo(nums, curr+1, curr, dp);
    //     }
    //     int exclude = 0+solveUsingMemo(nums, curr+1, prev, dp);

    //     dp[curr][prev+1] = max(include, exclude);
    //     return dp[curr][prev+1];
    // }
    // int solveUsingTabulation(vector<int>& nums)
    // {
    //     int n = nums.size();
    //     vector<vector<int> > dp(n+1 ,vector<int>(n+1, 0));

    //     for(int curr = n-1; curr>=0; curr--)
    //     {
    //         for(int prev = curr-1; prev>=-1;prev--)
    //         {
    //             int include = 0;
    //             if(prev == -1 || nums[curr] > nums[prev])
    //             {
    //                 include = 1+dp[curr+1][curr+1]; //yaha shifting karna hoga 
    //             }
    //             int exclude = 0+dp[curr+1][prev+1]; //yaha shifting karna hoga 
    //             dp[curr][prev+1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0]; //prev -> -1 so [-1+1] = [0]
    // }
    // int solveUsingTabulationSO(vector<int>& nums)
    // {
    //     int n = nums.size();
    //     vector<int> currRow(n+1, 0);
    //     vector<int> nextRow(n+1, 0);

    //     for(int curr = n-1; curr>=0; curr--)
    //     {
    //         for(int prev = curr-1; prev>=-1;prev--)
    //         {
    //             int include = 0;
    //             if(prev == -1 || nums[curr] > nums[prev])
    //             {
    //                 include = 1+nextRow[curr+1]; //yaha shifting karna hoga 
    //             }
    //             int exclude = 0+nextRow[prev+1]; //yaha shifting karna hoga 
    //             currRow[prev+1] = max(include, exclude);
    //         }
    //         nextRow = currRow;
    //     }
    //     return nextRow[0]; //prev -> -1 so [-1+1] = [0]
    // }
int solveUsingBinarySearch(vector<int>& nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
        int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
        //replace
            ans[index] = nums[i];
        }
    }
    return ans.size();
}
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans = solveUsingBinarySearch(nums);
    cout<<"Output :" << ans;
    return 0;
}
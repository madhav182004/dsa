#include<iostream>
#include<vector>
using namespace std;

// bool check(vector<int>& curr, vector<int>& prev)
// {
//     if(curr[0]>prev[0] && curr[1]>prev[1])
//     {
//         return true;
//     }
//     return false;
// }
// int solveUsingTabulationSO(vector<vector<int>>& envelopes)
// {
//     int n = envelopes.size();
//     vector<int> currRow(n+1, 0);
//     vector<int> nextRow(n+1, 0);

//     for(int curr = n-1;curr>=0;curr--)
//     {
//         for(int prev = curr-1;prev>=-1;prev--)
//         {
//             int include = 0;
//             if(prev == -1 || check(envelopes[curr], envelopes[prev]))
//             {
//                 include = 1 + nextRow[curr+1];
//             }
//             int exclude = 0 + nextRow[prev+1];
//             currRow[prev+1] = max(include, exclude);
//         }
//         nextRow = currRow;
//     }
//     return nextRow[0];
// }

static bool comp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int solveUsingBinarySearch(vector<vector<int>>& nums)
{
    sort(nums.begin(), nums.end(), comp);
    if(nums.size() == 0)
    {
        return 0;
    }
    vector<int> ans;
    ans.push_back(nums[0][1]);
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i][1] > ans.back())
        {
            ans.push_back(nums[i][1]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
            //replace
            ans[index] = nums[i][1];
        }
    }
    return ans.size();
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    // sort(envelopes.begin(), envelopes.end());
    int ans = solveUsingBinarySearch(envelopes);
    return ans;
}

int main()
{
    int m,n,target;
    cout << "Enter the number of envelopes:";
    cin >> m;
    vector<vector<int> > envelopes(m, vector<int>(2));
    cout << "Enter the values of envelopes:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> envelopes[i][j];
        }
    }
    int ans = maxEnvelopes(envelopes);
    cout << "Max Height: "<<ans;
}

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int findPairs(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int i=0;
    int j=1;
    while(j<nums.size())
    {
        int diff = nums[j]-nums[i];
        if(diff == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if(diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if(i==j)//imp
        {
            j++;
        }
    }
    return ans.size();
}
int main()
{
    int n, k;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k:";
    cin >> k;
    int ans = findPairs(nums, k);
    cout << "Total unique Pairs:" << ans << endl;
}
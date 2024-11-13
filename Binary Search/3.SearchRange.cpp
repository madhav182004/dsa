#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    //first occurence
    int s=0;
    int e=nums.size()-1;
    int mid;
    int ans1=-1;
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(nums[mid] == target)
        {
            ans1 = mid;
            e = mid - 1;
        }
        else if(target > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    //last occurence
    s=0;
    e=nums.size()-1;
    int ans2=-1;
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(nums[mid] == target)
        {
            ans2 = mid;
            s = mid + 1;
        }
        else if(target > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    vector<int> result;
    result.push_back(ans1);
    result.push_back(ans2);
    return result;
}

int main() 
{
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }
    cout << "Enter the target: ";
    cin >> target;
    vector<int> ans = searchRange(nums, target);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target)
{
    int s = 0;
    int e = nums.size()-1;
    int mid;
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(nums[mid] == target)
        {
            return mid;
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
    return -1;
}

int main()
{
    int n,target;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the target:";
    cin >> target;
    int ans = binarySearch(nums, target);
    if(ans == -1)
    {
        cout << "No such element found" << endl;
    }
    else
    {
        cout << "Target index:" << ans << endl;
    }
}
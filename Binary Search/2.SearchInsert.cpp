#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int s=0;
    int e=nums.size()-1;
    int mid, index;
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(nums[mid] == target)
        {
            index = mid;
            break;
        }
        else if(target > nums[mid])
        {
            index = mid + 1;
            s = mid + 1;
        }
        else
        {
            index = mid;
            e = mid - 1;
        }
    }
    return index;
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
    int ans = searchInsert(nums, target);
    cout << "Inseting/Present index:" << ans << endl;
}
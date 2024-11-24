#include<iostream>
#include<vector>
using namespace std;

int findMinInRotatedSorted(vector<int>& nums)
{
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    int mid;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        if(nums[low]<=nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }
        if(nums[low]<=nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    int ans = findMinInRotatedSorted(nums);
    cout << "Minimun element in Sorted Rotated Array is:" << ans << endl;
}
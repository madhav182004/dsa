#include<iostream>
#include<vector>
using namespace std;

int searchinRotatedSorted(vector<int>& nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (nums[mid] == target) return mid;

        //if left part is sorted:
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (nums[mid] <= target && target <= nums[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
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
    int ans = searchinRotatedSorted(nums, target);
    cout << "Element index:" << ans << endl;
}
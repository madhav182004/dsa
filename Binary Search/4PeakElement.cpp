#include<iostream>
#include<vector>
using namespace std;

int peakElement(vector<int>& nums)
{
    int s = 0;
    int e = nums.size()-1;
    int mid;
    while(s<e)
    {
        mid = s + (e-s)/2;
        if(nums[mid]<nums[mid+1])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
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
    int ans = peakElement(nums);
    cout << "Peak element index:" << ans << endl;
}
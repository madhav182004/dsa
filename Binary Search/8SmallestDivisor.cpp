#include<iostream>
#include<vector>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int s = 1;
    int e = *max_element(nums.begin(), nums.end());
    int ans = e;
    while (s <= e) 
    {
        int mid = s + (e - s) / 2;
        int sum = 0;
        for (int i=0;i<nums.size();i++) 
        {
            sum += ceil((double)nums[i] / mid);
        }
        if (sum <= threshold) 
        {
            ans = mid;
            e = mid - 1;
        } 
        else 
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, threshold;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the threshold:";
    cin >> threshold;
    int ans = smallestDivisor(nums, threshold);
    cout << "Smallest Divisor is:" << ans << endl;
}
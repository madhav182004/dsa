#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int sum = 0;
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];
        if(sum == k)
        {
            ans++;
        }
        for(int j=i+1;j<nums.size();j++)
        {
            sum += nums[j];
            if(sum == k)
            {
                ans++;
            }
        }
        sum = 0;
    }
    return ans;
}
int main() 
{
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    int ans = subarraySum(arr, k);
    cout << "The sum of subarrays is: " << ans << endl;
    return 0;
}
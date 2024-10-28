#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        ans^=nums[i];
    }
    return ans;
}
int main() 
{
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = singleNumber(nums);
    cout << "The single number is: " << ans << endl;
    return 0;
}

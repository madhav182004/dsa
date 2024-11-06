#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }
    for(int i=0;i< nums.size()/2;i++){
        nums[2*i] = pos[i];
        nums[2*i+1] = neg[i];
    }
    return nums;
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> ans = rearrangeArray(nums);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
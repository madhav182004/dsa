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
    int posUpdate=0;
    int negUpdate=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i%2 == 0)
        {
            nums[i]=pos[posUpdate];
            posUpdate++;
        }
        else
        {
            nums[i]=neg[negUpdate];
            negUpdate++;
        }
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
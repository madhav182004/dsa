#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int moreneeded = target - num;
        if(mpp.find(moreneeded) != mpp.end())
        {
            return vector<int>(mpp[moreneeded], i);
        }
        mpp[num] = i;
    }
    return vector<int>(-1, -1);
}

int main() 
{
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    
    vector<int> ans = twoSum(nums, target);
    if (ans[0] == -1 && ans[1] == -1)
    {
        cout << "No two sum solution found" << endl;
    }
    else
    {
        cout << "Indices: ";
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
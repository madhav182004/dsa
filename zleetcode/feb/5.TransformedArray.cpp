#include<iostream>
#include<vector>
using namespace std;

vector<int> transformedArray(vector<int>& nums)
{
    int n = nums.size();
    vector<int> result(n);
    for(int i=0;i<n;i++)
    {
        if(nums[i] == 0)
        {
            result[i] = 0;
        }
        else 
        {
            int idx = ((i + nums[i]) % n + n) % n;
            result[i] = nums[idx];
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {3, -2, 1, 1};
    vector<int> result = transformedArray(nums);
    for(int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
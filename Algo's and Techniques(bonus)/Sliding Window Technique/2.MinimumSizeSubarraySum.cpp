#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minSubArrayLen(vector<int>& nums, int target) {
    int s = 0;
    int e = 0;
    int len = INT_MAX;
    int sum = 0;
    while(e < nums.size())
    {
        sum += nums[e];
        while(sum >= target)
        {
            len = min(len, e-s+1);
            sum -= nums[s];
            s++;
        }
        e++;
    }
    if(len == INT_MAX)
    {
        return 0;
    }
    else
    {
        return len;
    }
}

int main() 
{
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array values: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of target: ";
    cin >> target;
    int ans = minSubArrayLen(nums, target);
    cout<<"Ans : "<<ans<<endl;
    return 0;
}
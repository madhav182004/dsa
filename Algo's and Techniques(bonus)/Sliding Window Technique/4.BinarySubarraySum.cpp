#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int target) {
    int s = 0;
    int e = 0;
    int sum = 0;
    int prefixZero = 0;
    int count = 0;
    while(e < nums.size())
    {
        sum += nums[e];
        while(s < e && (sum > target || nums[s] == 0))
        {
            if(nums[s] == 1)
            {
                prefixZero = 0;
            }
            else
            {
                prefixZero+=1;
            }
            sum -= nums[s];
            s++;
        }
        if(sum == target)
        {
            count += prefixZero + 1;
        }
        e++;
    }
    return count;
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
    int ans = numSubarraysWithSum(nums, target);
    cout<<"Ans : "<<ans<<endl;
    return 0;
}
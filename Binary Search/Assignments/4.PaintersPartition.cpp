#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool canAllocate(vector<int> &arr, int k, int maxTime)
{
    int s=1;
    int currSum=0;
    for(auto t:arr)
    {
        if(t > maxTime)
        {
            return false;
        }
        if(currSum + t <= maxTime)
        {
            currSum+=t;
        }
        else
        {
            s++;
            currSum = t;
            if(s > k)
            {
                return false;
            }
        }
    }
    return true;
}
int minTime(vector<int> &arr, int k) {
    int s = 0;
    int n = arr.size();
    if(k > n)
    {
        return -1;
    }
    int e = accumulate(arr.begin(), arr.end(), 0);
    int minAns = -1;
    while(s<=e)
    {
        int mid = (s+e) >> 1;
        if(canAllocate(arr, k, mid))
        {
            minAns = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return minAns;
}
int main()
{
    int n, k;
    cout << "Enter the size of arr: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the time for each block: ";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the no. of workers:";
    cin >> k;
    int ans = minTime(nums, k);
    cout << "Minimum Time to a worker is:" << ans << endl;
}
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool canAllocate(vector<int> &arr, int k, int maxPages)
{
    int s=1;
    int currSum=0;
    for(auto pages:arr)
    {
        if(pages > maxPages)
        {
            return false;
        }
        if(currSum + pages <= maxPages)
        {
            currSum+=pages;
        }
        else
        {
            s++;
            currSum = pages;
            if(s > k)
            {
                return false;
            }
        }
    }
    return true;
}
int findPages(vector<int> &arr, int k) {
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
    cout << "Enter the number of books:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the pages in each book:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the no. of students:";
    cin >> k;
    int ans = findPages(nums, k);
    cout << "Minimum Pages to a student is:" << ans << endl;
}
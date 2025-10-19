#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({nums[i], i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++)
    {
        pq.push({nums[i], i});
        while(pq.top().second <= i-k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

int main() 
{
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array values: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int>ans = maxSlidingWindow(nums, k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
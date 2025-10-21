#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> temp;
    for(int i=0;i<nums.size();i++)
    {
        int index = i;
        int value = nums[i];
        pair<int, int> p = make_pair(value, index);
        temp.push_back(p);
    }
    sort(temp.begin(), temp.end());
    int s = 0;
    int e = nums.size()-1;
    vector<int> ans;
    while(s<e)
    {
        int sum = temp[s].first + temp[e].first;
        if(sum == target)
        {
            ans.push_back(temp[s].second);
            ans.push_back(temp[e].second);
            return ans;
        }
        else if(sum>target)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return ans;
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
    cout << "Enter the target: ";
    cin >> target;
    vector<int>ans = twoSum(nums, target);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
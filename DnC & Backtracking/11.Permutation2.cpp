#include<iostream>
using namespace std;

void permutation2(vector<int>& nums, vector<vector<int> >& ans, int start)
{
    if(start >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_map<int, bool>visited;
    for(int i=start;i<nums.size();i++)
    {
        if(visited.find(nums[i]) != visited.end())
        {
            continue;
        }
        visited[nums[i]] = true;
        swap(nums[i], nums[start]);
        permutation2(nums, ans, start+1);
        swap(nums[i], nums[start]);
    }
}

int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<< "Enter the array elemets: "<< endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    cout<<endl;
    vector<vector<int> > ans;
    permutation2(nums, ans, 0);
    
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
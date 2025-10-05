#include<iostream>
#include<vector>
using namespace std;

vector<int> findMajority(vector<int> &arr)
{
    int n = arr.size();
    int check = floor(n/3);
    unordered_map<int, int> freq;
    vector<int> ans;
    for(int i : arr)
    {
        freq[i]++;
    }
    for(auto& p : freq)
    {
        if(p.second>check)
        {
            ans.push_back(p.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans;
    ans = findMajority(arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
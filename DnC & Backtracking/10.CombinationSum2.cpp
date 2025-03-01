#include<iostream>
#include<vector>
using namespace std;

void combinationSum2(vector<int>& candidates, int target, vector<int>& v, vector<vector<int> >& ans, int index)
{
    if(target == 0)
    {
        ans.push_back(v);
        return;
    }
    if(target < 0)
    {
        return;
    }
    for(int i = index;i<candidates.size();i++)
    {
        //for no duplicate entries
        if(i > index && candidates[i] == candidates [i-1])
        {
            continue;
        }
        v.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], v, ans, i+1); //so that each candidate is only used once
        v.pop_back();
    }
}
int main(){
    vector<int> candidates;
    int n, target;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<< "Enter the array elemets: "<< endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        candidates.push_back(a);
    }
    cout<<"Enter the target: ";
    cin>>target;
    vector<int> v;
    vector<vector<int> > ans;
    sort(candidates.begin(), candidates.end()); //sort to avoid duplicates
    combinationSum2(candidates, target, v, ans, 0);
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
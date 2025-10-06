#include<iostream>
#include<vector>
using namespace std;

int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int ans = arr[n-1] - arr[0];

    for(int i=0;i<n-1;i++)
    {
        int mini = min(arr[0]+k, arr[i+1]-k);
        int maxi = max(arr[i]+k, arr[n-1]-k);
        if(mini < 0)
        {
            continue;
        }
        ans = min(ans, maxi-mini);
    }
    return ans;
}

int main()
{
    int n, k;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    int ans;
    ans = getMinDiff(arr, k);
    cout<<"Min Diff: "<<ans<<endl;
    return 0;
}
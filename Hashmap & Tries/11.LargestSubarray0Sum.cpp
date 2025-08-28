#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxLen(vector<int>& arr)
{
    unordered_map<int, int> mapping;
    int csum = 0;
    int ans = 0;
    for(int i=0;i<arr.size();i++)
    {
        csum += arr[i];
        if(csum == 0)
        {
            ans = max(ans, i+1);
        }
        else if(mapping.find(csum) == mapping.end())
        {
            mapping[csum] = i;
        }
        else
        {
            ans = max(ans, i - mapping[csum]);
        }
    }
    return ans;
}
int main()
{
    int n,target;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int ans = maxLen(arr);
    cout << "Max Length of Subarray with sum 0 is : "<< ans << endl;
    return 0;
}
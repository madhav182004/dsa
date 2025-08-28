#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool findPairs(vector<int>& arr)
{
    unordered_map<int, bool> mapping;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            int sum = arr[i]+arr[j];
            if(mapping.find(sum)!=mapping.end())
            {
                return true;
            }
            else
            {
                mapping[sum] = true;
            }
        }
    }
    return false;
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
    if(findPairs(arr))
    {
        cout << "Pairs found" << endl;
    }
    else
    {
        cout << "No pairs exist" << endl;
    }
    return 0;
}
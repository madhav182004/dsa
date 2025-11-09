#include<iostream>
#include<vector>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int l=0;
    int h=arr.size()-1;
    while(h-l >= k)
    {
        if(x-arr[l] > arr[h]-x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return vector<int>(arr.begin()+l, arr.begin()+h+1);
}
int main()
{
    int n, k, x;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k:";
    cin >> k;
    cout << "Enter the value of x:";
    cin >> x;
    vector<int> ans = findClosestElements(nums, k, x);
    cout << "Kth closest elements are: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
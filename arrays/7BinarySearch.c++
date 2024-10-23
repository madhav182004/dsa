#include<iostream>
#include<vector>
using namespace std;
bool binarySearch(vector<int>& nums, int k) 
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(nums[mid]==k)
        {
            return true;
        }
        else if(nums[mid]<k)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return false;
}
int main()
{
    int n,k;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int> nums(n);
    if(n==0)
    {
        cout<<"Array is empty";
        return 0;
    }
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout<<"Enter the element to search in the array:";
    cin>>k;
    bool ans = binarySearch(nums, k);
    if(ans == true)
    {
        cout<<"Element found";
    }
    else
    {
        cout<<"Element not found";
    }
}
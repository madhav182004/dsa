#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int s=0;
    int e=nums.size()-1;
    int ans = -1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        int diff = nums[mid]-mid;
        if(diff==0)
        {
            s=mid+1;
        }
        else
        {
            ans=mid;
            e=mid-1;
        }
    }
    if(ans==-1)
    {
        return nums.size();
    }
    return ans;
}
int main()
{
    int n;
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
    int ans = missingNumber(nums);
    cout<<"The missing element is"<< ans;
}
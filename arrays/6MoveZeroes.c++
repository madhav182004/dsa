#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        return;
    }
    for(int i=j+1;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
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
    moveZeroes(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
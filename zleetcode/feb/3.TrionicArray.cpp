#include<iostream>
#include<vector>
using namespace std;

bool isTrionic(vector<int>& nums)
{
    int n = nums.size();
    int i = 0;
    while(i+1 < n && nums[i] < nums[i+1])
    {
        i++;
    }
    if(i == 0)
    {
        return false;
    }
    int p = i;
    while(i+1 < n && nums[i] > nums[i+1])
    {
        i++;
    }
    if(i == p || i == n - 1)
    {
        return false;
    }
    while(i+1 < n && nums[i] < nums[i+1])
    {
        i++;
    }
    return i == n-1;        
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
    if(isTrionic(nums))
    {
        cout<<"Trionic"<<endl;
    }
    else
    {
        cout<<"Not Trionic"<<endl;
    }
    return 0;
}
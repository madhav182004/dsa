#include <iostream>
#include <vector>
using namespace std;

int repeatedNTimes(vector<int>& nums)
{
    int n = nums.size()/2;
    unordered_map<int, int> freq;
    for(auto num:nums)
    {
        freq[num]++;
        if(freq[num] > 1)
        {
            return num;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter the size of arr: ";
    cin>>n;
    vector<int> nums(n);
    cout<<endl<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout << "Ans : " << repeatedNTimes(nums) << endl;
    return 0;
}

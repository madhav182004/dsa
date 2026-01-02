#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool compare(int a, int b)
{
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}

string largestNumber(vector<int> &nums)
{
    string ans = "";
    sort(nums.begin(), nums.end(), compare);
    for(auto num:nums)
    {
        ans+=to_string(num);
    }
    if(ans[0] == '0')
    {
        return "0";
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    string ans = largestNumber(nums);
    cout << "Largest Number : " << ans << endl;
    return 0;
}
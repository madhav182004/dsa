#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    int left = 0;
    int right = n-1;
    while(index<=right)
    {
        if(nums[index]==0)
        {
            swap(nums[index], nums[left]);
            left++;
            index++;
        }
        else if(nums[index]==2)
        {
            swap(nums[index], nums[right]);
            right--;
        }
        else
        {
            index++;
        }
    }
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int sumFourDivisors(vector<int>& nums)
{
    int ans = 0;
    for(int n:nums)
    {
        int d = 0;
        int totalSum = 0;
        for (int i=1;i*i<=n;i++)
        {
            if (n % i == 0)
            {
                int j = n/i;
                if (i == j)
                {
                    d += 1;
                    totalSum += i;
                }
                else
                {
                    d += 2;
                    totalSum += i + j;
                }
            }
            if(d > 4)
            {
                break;
            }
        }
        if(d == 4) 
        {
            ans += totalSum;
        }
    }
    return ans;
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
    cout << "Ans : " << sumFourDivisors(nums) << endl;
    return 0;
}

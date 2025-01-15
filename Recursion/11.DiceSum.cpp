#include<iostream>
using namespace std;

int diceSum(int n, int k, int target)
{
    if(target < 0)
    {
        return 0;
    }
    if(n==0 && target==0)
    {
        return 1;
    }
    if(n==0 && target==0)
    {
        return 0;
    }
    if(n==0 && target==0)
    {
        return 0;
    }

    int ans = 0;
    for(int i=1;i<=k;i++)
    {
        ans = ans + diceSum(n-1, k, target - i);
    }
    return ans;
}
int main()
{
    int n, k, target;
    cout << "Enter the number of dices : ";
    cin>>n;
    cout << "Enter the number of faces of dices : ";
    cin>>k;
    cout << "Enter the target : ";
    cin>>target;
    int ans = diceSum(n, k, target);
    cout<<"The no. of possible ways are: " << ans;
    return 0;
}
#include<iostream>
using namespace std;

int climbStairs(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    int ans = climbStairs(n-1)+climbStairs(n-2);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of stairs:";
    cin >> n;
    int ans = climbStairs(n);
    cout << "The no. of possible ways are: "<< ans << endl;
}
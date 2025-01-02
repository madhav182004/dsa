#include<iostream>
using namespace std;

int maximizeTheCut(int n, int x, int y, int z)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }

    int option1 = 1 + maximizeTheCut(n-x, x, y, z);
    int option2 = 1 + maximizeTheCut(n-y, x, y, z);
    int option3 = 1 + maximizeTheCut(n-z, x, y, z);

    int finalAns = max(option1, max(option2, option3));
    return finalAns;
}
int main()
{
    int n, x, y, z;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Enter the value of x:";
    cin>>x;
    cout<<"Enter the value of y:";
    cin>>y;
    cout<<"Enter the value of z:";
    cin>>z;
    int ans = maximizeTheCut(n, x, y, z);
    cout<<"Output: "<<ans;
}
#include<iostream>
using namespace std;

double mpow(double x, int n)
{
    if(n == 0)
    {
        return 1.0;
    }
    if(n < 0)
    {
        if(n == INT_MIN)
        {
            return 1.0/ (mpow(x, INT_MIN)* x);
        }
        else
        {
            return 1.0/ mpow(x, -n);
        }
    }
    double half = mpow(x, n / 2);
    if(n % 2 == 0)
    {
        return half*half;
    }
    else
    {
        return half*half*x;
    }
}
int main()
{
    double x;
    int n;
    cout << "Enter the value of x:";
    cin >> x;
    cout << "Enter the value of n:";
    cin >> n;
    double ans = mpow(x, n);
    cout<< "The ans is:" << ans;
    return 0;
}
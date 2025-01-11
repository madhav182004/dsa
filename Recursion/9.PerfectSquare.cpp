#include<iostream>
using namespace std;

int numPerfectSquareHelper(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while(i <= end)
    {
        int perfectSquare = i*i;
        int numberOfPerfectSquares = 1 + numPerfectSquareHelper(n - perfectSquare);
        if(numberOfPerfectSquares < ans)
        {
            ans = numberOfPerfectSquares;
        }
        ++i;
    }
    return ans;
}
int numPerfectSquare(int n)
{
    return numPerfectSquareHelper(n) - 1;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin>>n;
    int ans = numPerfectSquare(n);
    cout<<"The no. of perfect squares are: " << ans;
    return 0;
}
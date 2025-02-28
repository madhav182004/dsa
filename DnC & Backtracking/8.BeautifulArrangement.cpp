#include<iostream>
#include<vector>
using namespace std;

void countArrangements(vector<int>& v, int &n, int &ans, int currNum)
{
    if(currNum == n+1)
    {
        ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum;
            countArrangements(v, n, ans, currNum+1);
            v[i] = 0; //backtracking
        }
    }
}
int main()
{
    int n;
    int ans = 0;
    vector<int> v(n+1);
    cout<<"Enter the value of n: ";
    cin>>n;
    countArrangements(v, n, ans, 1);
    cout<<"Number of beautiful arrangements are: "<< ans <<endl;
}
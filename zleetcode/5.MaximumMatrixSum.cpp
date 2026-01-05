#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix)
{
    long long sumAbs=0;
    int negCount=0;
    int minAbs=INT_MAX;
    for(auto &row:matrix)
    {
        for(int val:row)
        {
            if(val < 0)
            {
                negCount++;
            }
            sumAbs += abs(val);
            minAbs = min(minAbs, abs(val));
        }
    }
    if (negCount%2==0)
    {
        return sumAbs;
    }
    else
    {
        return sumAbs-2LL*minAbs;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of matrix (n x n): ";
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout<<"Enter the matrix elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<"Ans : "<<maxMatrixSum(matrix)<<endl;
    return 0;
}

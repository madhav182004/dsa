#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char> >& matrix, int i, int j, int row, int col, int& maxi)
{
    if(i >= row || j >= col)
    {
        return 0;
    }
    int right = maximalSquare(matrix, i, j+1, row, col, maxi);
    int diagonal = maximalSquare(matrix, i+1, j+1, row, col, maxi);
    int down = maximalSquare(matrix, i+1, j, row, col, maxi);

    if(matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int m,n;
    cout << "Enter the value of m:";
    cin >> m;
    cout << "Enter the value of n:";
    cin >> n;
    int i = 0;
    int j = 0;
    int maxi = 0;
    vector<vector<char> > matrix(m, vector<char>(n));
    cout << "Enter the elements of the matrix:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
        }
    }
    // int ans = maximalSquare(matrix, i, j, m, n, maxi);
    maximalSquare(matrix, i, j, m, n, maxi);
    cout << "Output: " << maxi*maxi << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool searchinRowandColSortedMatrix(vector<vector<int> >& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int col = n - 1;
    while( row<m && col>=0 )
    {
        if(matrix[row][col] == target)
        {
            return true;
        }
        else if(matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}
int main()
{
    int m,n,target;
    cout << "Enter the value of m:";
    cin >> m;
    cout << "Enter the value of n:";
    cin >> n;
    vector<vector<int> > matrix(m, vector<int>(n));
    cout << "Enter the elements of the 2D array:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter the target:";
    cin >> target;
    bool ans = searchinRowandColSortedMatrix(matrix, target);
    if(ans == true)
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }
}
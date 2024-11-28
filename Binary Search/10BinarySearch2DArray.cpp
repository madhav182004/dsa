#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    int s1 = 0;
    int e1 = matrix.size()-1;
    int mid1;
    while(s1<=e1)
    {
        mid1 = s1+(e1-s1)/2;
        int s = 0;
        int e = matrix[mid1].size()-1;
        int mid;
        while(s<=e)
        {
            mid = s+(e-s)/2;
            if(matrix[mid1][mid] == target)
            {
                return true;
            }
            else if(matrix[mid1][mid] < target)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        if(matrix[mid1][0] < target)
        {
            s1 = mid1+1;
        }
        else
        {
            e1 = mid1-1;
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
    bool ans = searchMatrix(matrix, target);
    if(ans == true)
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }
}
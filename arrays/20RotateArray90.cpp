#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<matrix[i].size();j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
    // for(int i=0;i<n;i++)
    // {
    //     reverse(matrix[i].begin(), matrix[i].end());
    // }
}

int main() 
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    rotate(matrix);

    cout << "Rotated Array: " << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr)
{
    int count = 0;
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
        else
        {
            count=0;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxOnes = maxConsecutiveOnes(arr);
    cout << "The maximum consecutive one's is: " << maxOnes << endl;
    return 0;
}

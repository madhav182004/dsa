#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int getLargest(vector<int> &arr) 
{
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    if(n==0)
    {
        cout << "Array is empty.";
        return 0;
    }
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int largest = getLargest(arr);
    cout << "The largest element is: " << largest << endl;
    return 0;
}
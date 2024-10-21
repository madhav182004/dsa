#include<iostream>
#include<vector>
using namespace std;

bool sortedRotated(vector<int> &arr)
{
    int outofOrder=0;
    int arrsize=arr.size();
    for(int i=0;i<arrsize;i++)
    {
        if(arr[i] > arr[(i+1)% arrsize])
        {
            outofOrder++;
        }
    }
    return outofOrder<=1;
}
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    vector<int> arr(n);
    if(n==0)
    {
        cout<<"Array is empty";
        return 0;
    }
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool ans = sortedRotated(arr);
    if(ans == true)
    {
        cout<<"Array is Sorted Rotated";
    }
    else
    {
        cout<<"Array is not Sorted Rotated";
    }
}
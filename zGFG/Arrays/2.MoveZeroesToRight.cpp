#include<iostream>
#include<vector>
using namespace std;

void moveZeroesToRight(vector<int>& arr)
{
    int index = 0;
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            arr[index] = arr[i];
            index++;
        }
    }
    for(int i=index;i<n;i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    moveZeroesToRight(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
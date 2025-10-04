#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int i = n-2;
    while(i>=0 && arr[i]>=arr[i+1])
    {
        i--;
    }
    if(i>=0)
    {
        int j=n-1;
        while(arr[j]<=arr[i])
        {
            j--;
        }
        swap(arr[i], arr[j]);
    }
    reverse(arr.begin()+i+1, arr.end());
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
    nextPermutation(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
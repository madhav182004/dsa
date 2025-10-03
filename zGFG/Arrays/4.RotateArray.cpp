#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int> &arr, int k)
{
    k = k%arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end()-k);
    reverse(arr.end()-k, arr.end());
}

int main()
{
    int n, k;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    rotateArray(arr, k);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> &arr)
{
    int j=1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]!=arr[i-1])
        {
            arr[j]=arr[i];
            j++;
        }
    }
    return j;
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
    int ans = removeDuplicate(arr);
    for(int i=0;i<ans;i++)
    {
        cout<<arr[i]<<" ";
    }
}

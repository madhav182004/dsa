#include<iostream>
#include<vector>
using namespace std;

int mergeArr(vector<int> &arr,vector<int> &temp, int s, int mid, int e)
{
    int i = s;
    int j = mid+1;
    int k = s;
    int c = 0;

    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else //inversion case
        {
            temp[k++] = arr[j++];
            c += mid - i + 1;
        }
    }
    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=e)
    {
        temp[k++] = arr[j++];
    }
    while(s<=e)
    {
        arr[s] = temp[s];
        s++;
    }

    return c;
}

int mergeSort(vector<int> &arr,vector<int> &temp, int s, int e)
{
    if(s>=e)
    {
        return 0;
    }

    int mid = s+(e-s)/2;
    int c = 0;

    c += mergeSort(arr, temp, s, mid);
    c += mergeSort(arr, temp, mid+1, e);
    
    c += mergeArr(arr, temp, s, mid, e);

    return c;
}

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> temp(n, 0);
    int s = 0;
    int e = n - 1;
    int c = 0;

    cout<< "Enter the array elemets: "<< endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<endl;

    c = mergeSort(arr, temp, s, e);
    
    cout<< "No of inversions: "<<c;
}
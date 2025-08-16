#include<iostream>
#include<queue>
using namespace std;

int getkthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[7] = {3, 7, 4, 5, 6, 8, 9};
    cout<<"Printing heap:"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k;
    cout<<"Enter k:"<<endl;
    cin>>k;
    int ans = getkthSmallestElement(arr, 7, k);
    cout<<"Kth smallest element: "<< ans <<endl;
}
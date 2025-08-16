#include<iostream>
using namespace std;

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestIndex = index;

    if(leftIndex<=n && arr[largestIndex]<arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if(rightIndex<=n && arr[largestIndex]<arr[rightIndex])
    {
        largestIndex = rightIndex;
    }
    if(index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n)
{
    while(n!=1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr,n,1);
    }
}

int main()
{
    int arr[7] = {-1, 25, 20, 15, 5, 10, 12};
    cout<<"Printing heap:"<<endl;
    for(int i=1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr, 6);
    cout<<"Printing sorted heap:"<<endl;
    for(int i=1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
}
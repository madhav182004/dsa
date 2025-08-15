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

void buildHeap(int arr[], int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[7] = {-1, 5, 10, 15, 20, 25, 12};
    cout<<"Printing array:"<<endl;
    for(int i=1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    buildHeap(arr, 6);
    cout<<"Printing heap:"<<endl;
    for(int i=1;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
}
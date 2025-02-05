#include<iostream>
using namespace std;

void mergeArr(int arr[], int s, int e)
{
    int mid = s+(e-s)/2;
    int lenghtLeft = mid - s + 1;
    int lengthRight = e - mid;

    int *leftArr = new int[lenghtLeft];
    int *rightArr = new int[lengthRight];

    int k = s;

    for(int i=0;i<lenghtLeft;i++)
    {
        leftArr[i] = arr[k];
        k++;
    }

    k = mid+1;

    for(int i=0;i<lengthRight;i++)
    {
        rightArr[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = s;

    while(leftIndex < lenghtLeft && rightIndex < lengthRight)
    {
        if(leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrIndex] = leftArr[leftIndex];
            mainArrIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrIndex] = rightArr[rightIndex];
            mainArrIndex++;
            rightIndex++;
        }
    }
    while(rightIndex < lengthRight)
    {
            arr[mainArrIndex] = rightArr[rightIndex];
            mainArrIndex++;
            rightIndex++;
    }
    while(leftIndex < lenghtLeft)
    {
            arr[mainArrIndex] = leftArr[leftIndex];
            mainArrIndex++;
            leftIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    
    mergeArr(arr, s, e);
}

int main(){
    int arr[]={3,1,6,9,4,2};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout<< "Before Merge Sort: "<< endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, s, e);
    
    cout<< "After Merge Sort: "<< endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
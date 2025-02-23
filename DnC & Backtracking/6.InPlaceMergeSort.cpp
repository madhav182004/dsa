#include<iostream>
#include<vector>
using namespace std;

void mergeInPlace(int arr[], int s, int e) //gap method
{
    int totalsize = e - s + 1;
    int gap = (totalsize/2) + (totalsize%2); //ceil
    while(gap > 0)
    {
        int i = s;
        int j = s + gap;
        while(j <= e)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }
        gap = gap<=1 ? 0 : (gap / 2) + (gap % 2);
    }
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
    
    mergeInPlace(arr, s, e);
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
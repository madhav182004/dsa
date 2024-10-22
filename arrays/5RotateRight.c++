#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &arr, int low, int high)
    {
        while(low<=high)
        {
            int temp = arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
            low++;
            high--;
        }
    }
void rotateRight(vector<int> &arr, int k) {
    int n = arr.size();
    k = k % n;
    //for first n-k elements
    reverse(arr,0,n-k-1);
    //for next remaining elements
    reverse(arr,n-k,n-1);
    //whole reverse
    reverse(arr,0,n-1);
}
int main()
{
    int n,k;
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
    cout<<"Enter the value of k:";
    cin>>k;
    rotateRight(arr,k);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
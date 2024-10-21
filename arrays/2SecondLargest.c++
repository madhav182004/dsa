#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int getSecondLargest(vector<int> &arr) 
{
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int second = INT_MAX;
    int temp = INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        int diff=max-arr[i];
        if(diff!=0 && diff<temp)
        {
            temp = diff;
            second = arr[i];
        }
    }
    if(second == INT_MAX)
    {
        return -1;
    }
    else{
        return second;
    }
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int secondLargest = getSecondLargest(arr);
    if(secondLargest != -1) {
        cout << "The second largest element is: " << secondLargest << endl;
    } else {
        cout << "There is no second largest element." << endl;
    }
    return 0;
}

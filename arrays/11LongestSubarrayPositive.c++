#include<iostream>
#include<vector>
using namespace std;

int getLongestArrayPositive(vector<int> &a, int n, int k)
{
    int l=0,r=0;
    int sum = a[0];
    int maxlen = 0;
    while(r<n)
    {
        while(l<=r && sum>k)
        {
            sum = sum - a[l];
            l++;
        }
        if(sum == k)
        {
            maxlen = max(maxlen, r-l+1);
        }
        r++;
        if(r<n)
        {
            sum = sum + a[r];
        }
    }
    return maxlen;
}
int main() 
{
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    int sub = getLongestArrayPositive(arr, n, k);
    cout << "The longest subarray is: " << sub << endl;
    return 0;
}

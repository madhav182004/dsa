#include<iostream>
#include<vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int s = 0;
    int e = arr.size()-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        int missing = arr[mid] - (mid+1);
        if(missing<k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return k+e+1;
}
int main()
{
    int n, k;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of k:";
    cin >> k;
    int ans = findKthPositive(arr, k);
    cout << "Kth missing element is:" << ans << endl;
}
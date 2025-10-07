#include<iostream>
#include<vector>
using namespace std;

int maxSubarrayProduct(vector<int> &arr)
{
    int minProduct = arr[0];
    int maxProduct = arr[0];
    int result = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] < 0)
        {
            swap(maxProduct, minProduct);
        }
        maxProduct = max(arr[i], maxProduct*arr[i]);
        minProduct = min(arr[i], minProduct*arr[i]);
        
        result = max(result, maxProduct);
    }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans;
    ans = maxSubarrayProduct(arr);
    cout<<"Max Subarray Product: "<<ans<<endl;
    return 0;
}
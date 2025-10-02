#include<iostream>
#include<vector>
using namespace std;

int secondLargest(vector<int> &arr)
{
    int max1 = -1, max2 = -1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2 && arr[i] < max1)
        {
            max2 = arr[i];
        }
    }
    return max2;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = secondLargest(arr);
    if(ans != -1)
    {
        cout << "The second largest element is: " << ans << endl;
    }
    else
    {
        cout << "There is no second largest element." << endl;
    }
    return 0;
}
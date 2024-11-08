#include<iostream>
#include<vector>
using namespace std;

vector<int> arrayLeaders(vector<int>& arr)
{
    vector<int> out;
    int n = arr.size();
    int index = n-1;
    out.push_back(arr[index]);
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[index])
        {
            out.push_back(arr[i]);
            index = i;
        }
    }
    reverse(out.begin(), out.end());
    return out;
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
    vector<int> ans = arrayLeaders(arr);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
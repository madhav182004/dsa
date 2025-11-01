#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int firstRepeated(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for(int e:arr)
    {
        freq[e]++;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(freq[arr[i]] > 1)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int n;
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
    int ans = firstRepeated(arr);
    cout<<"Index of first repeated is: "<< ans<<endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minCost(vector<int> &arr) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<arr.size();i++)
    {
        int val = arr[i];
        minHeap.push(val);
    }
    int cost = 0;
    while(minHeap.size() > 1)
    {
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        cost += a+b;
        int sum = a+b;
        minHeap.push(sum);
    }
    return cost;
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the size of ropes: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = minCost(arr);
    cout<<"Cost : "<<ans<<endl;
    return 0;
}

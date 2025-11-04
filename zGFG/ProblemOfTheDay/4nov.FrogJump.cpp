#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>& height)
{
    int n = height.size();
    int prev=0, prev2=0;
    for(int i=1;i<n;i++)
    {
        int jumpOne = prev+abs(height[i]-height[i-1]);
        int jumpTwo = INT_MAX;
        if (i > 1)
        {
            jumpTwo = prev2+abs(height[i]-height[i-2]);
        }
        int curr = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int ans = minCost(height);
    cout<<"Total Cost : "<<ans<<endl;
    return 0;
}
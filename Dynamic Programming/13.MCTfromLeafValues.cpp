#include<iostream>
#include<vector>
#include <map>
using namespace std;

// int solveUsingRec(vector<int>& arr, map< pair<int, int>, int >& maxi, int s, int e)
// {
//     if(s >= e)
//     {
//         return 0;
//     }
//     int ans = INT_MAX;
//     for(int i=s; i<e; i++)
//     {
//         ans = min(ans, (maxi[{s,i}] * maxi[{i+1,e}])+
//                     solveUsingRec(arr, maxi, s, i)+
//                     solveUsingRec(arr, maxi, i+1, e));
//     }
//     return ans;
// }
// int solveUsingMemo(vector<int>& arr, map< pair<int, int>, int >& maxi, int s, int e, vector<vector<int>>& dp)
// {
//     if(s >= e)
//     {
//         return 0;
//     }
//     if(dp[s][e] != -1)
//     {
//         return dp[s][e];
//     }
//     int ans = INT_MAX;
//     for(int i=s; i<e; i++)
//     {
//         ans = min(ans, (maxi[{s,i}] * maxi[{i+1,e}])+
//                     solveUsingMemo(arr, maxi, s, i, dp)+
//                     solveUsingMemo(arr, maxi, i+1, e, dp));
//     }
//     dp[s][e] = ans;
//     return dp[s][e];
// }
int solveUsingTabulation(vector<int>& arr, map< pair<int, int>, int >& maxi)
{
    int n = arr.size();
    vector<vector<int> >dp(n+1, vector<int> (n+1, 0));
    for(int start_index = n;start_index>=0;start_index--)
    {
        for(int end_index = 0; end_index<=n-1;end_index++)
        {
            if(start_index >= end_index)
            {
                continue;
            }
            int ans = INT_MAX;
            for(int i=start_index; i<end_index; i++)
            {
                ans = min(ans, (maxi[{start_index,i}] * maxi[{i+1,end_index}])+
                            dp[start_index][i]+
                            dp[i+1][end_index]);
            }
            dp[start_index][end_index] = ans;
        }
    }
    return dp[0][n-1];
}
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    //pre computation
    map< pair<int, int>, int > maxi;
    for(int i=0; i<n; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<n; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }
    // int start = 0;
    // int end = n-1;
    // vector<vector<int> >dp(n+1, vector<int> (n+1, -1));
    int ans = solveUsingTabulation(arr, maxi);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of arr : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the values of arr: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = mctFromLeafValues(arr);
    cout<<"Output :" << ans << endl;
    return 0;
}
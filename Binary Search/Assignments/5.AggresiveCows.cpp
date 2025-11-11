#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool canPlaceCows(vector<int> &stalls, int k, int ansCheck)
{
    int c = 1;
    int pos = stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
        if(stalls[i] - pos >= ansCheck)
        {
            c++;
            pos = stalls[i];
        }
        if(c==k)
        {
            return true;
        }
    }
    return false;
}
int minTime(vector<int> stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e=stalls[stalls.size()-1] - stalls[0];
    int ansMaxofMin = -1;
    while(s<=e)
    {
        int mid = (s+e) >> 1;
        if(canPlaceCows(stalls, k, mid))
        {
            ansMaxofMin = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ansMaxofMin;
}
int main()
{
    int n, k;
    cout << "Enter the size of stalls: ";
    cin >> n;
    vector<int> stalls(n);
    cout << "Enter the stalls distance: ";
    for(int i=0;i<n;i++)
    {
        cin >> stalls[i];
    }
    cout << "Enter the no. of aggresive cows:";
    cin >> k;
    int ans = minTime(stalls, k);
    cout << "Minimum distance for two cows is:" << ans << endl;
}
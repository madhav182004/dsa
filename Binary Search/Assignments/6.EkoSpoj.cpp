#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int k, long long int ansCheck)
{
    long long int woodCollected = 0;
    for(long long int i=0;i<trees.size();i++)
    {
        if(trees[i] > ansCheck)
        {
            woodCollected += trees[i] - ansCheck;
        }
    }
    return woodCollected>=k;
}
long long int maxSawBladeHeight(vector<long long int> trees, long long int k)
{
	long long int s=0;
	long long int e=*max_element(trees.begin(), trees.end());
    long long int ans = -1;
    while(s<=e)
    {
        long long int mid = s+(e-s)/2;
        if(isPossibleSolution(trees, k, mid))
        {
            ans = mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    long long int n, k;
    cout << "Enter the size of arr: ";
    cin >> n;
    vector<long long int> trees(n);
    cout << "Enter the heights of trees: ";
    for(int i=0;i<n;i++)
    {
        cin >> trees[i];
    }
    cout << "Enter the desired number of meters of wood:";
    cin >> k;
    cout << "Saw blade level: " << maxSawBladeHeight(trees, k) << endl;
    return 0;
}
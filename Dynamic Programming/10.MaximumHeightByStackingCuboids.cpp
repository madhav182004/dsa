#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& curr, vector<int>& prev)
{
    if(curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2])
    {
        return true;
    }
    return false;
}
int solveUsingTabulationSO(vector<vector<int>>& cuboids)
{
    int n = cuboids.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr = n-1;curr>=0;curr--)
    {
        for(int prev = curr-1;prev>=-1;prev--)
        {
            int include = 0;
            if(prev == -1 || check(cuboids[curr], cuboids[prev]))
            {
                int height = cuboids[curr][2];
                include = height + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];
            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto& cuboid:cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = solveUsingTabulationSO(cuboids);
    return ans;
}

int main()
{
    int m,n,target;
    cout << "Enter the number of cuboids:";
    cin >> m;
    vector<vector<int> > cuboids(m, vector<int>(3));
    cout << "Enter the values of cuboids:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> cuboids[i][j];
        }
    }
    int ans = maxHeight(cuboids);
    cout << "Max Height: "<<ans;
}

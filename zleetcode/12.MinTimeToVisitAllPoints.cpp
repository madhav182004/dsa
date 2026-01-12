#include <iostream>
#include <vector>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points)
{
    int t = 0;
    for (int i=1;i<points.size();i++)
    {
        int dx=abs(points[i][0]-points[i-1][0]);
        int dy=abs(points[i][1]-points[i-1][1]);
        t+=max(dx, dy);
    }
    return t;
}
int main()
{
    int n;
    cout << "Enter number of points: ";
    cin>>n;
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter points (x y):" << endl;
    for (int i=0;i<n;i++)
    {
        cin>>points[i][0]>>points[i][1];
    }
    cout << "Ans : " << minTimeToVisitAllPoints(points) << endl;
    return 0;
}
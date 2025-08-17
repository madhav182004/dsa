#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class myComp{
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA > distB;
        }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
    for(auto p:points)
    {
        pq.push({p[0], p[1]});
    }
    while(!pq.empty() && k--)
    {
        auto& top = pq.top();
        ans.push_back({top.first, top.second});
        pq.pop();
    }
    return ans;
}

int main()
{
    int n, m, k;
    cout << "Enter the value of n: "<<endl;
    cin >> n;
    vector<vector<int> > points(n, vector<int>(2));
    vector<vector<int>> ans;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) 
    {
        for(int j=0;j<2;j++)
        {
            cin >> points[i][j];
        }
    }
    cout<<"Enter k:"<<endl;
    cin>>k;
    ans = kClosest(points, k);
    cout<<"K Closest element are: "<<endl;
    for (auto &p : ans)
    {
        cout << p[0] << ", " << p[1] << endl;
    }
}
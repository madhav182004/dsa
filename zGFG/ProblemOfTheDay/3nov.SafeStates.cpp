#include<iostream>
#include<vector>
using namespace std;

vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    vector<vector<int>> rev(V);
    vector<int> indegree(V, 0);
    for(auto e:edges)
    {
        rev[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }
    queue<int> q;
    vector<int> safe;
    for(int i=0;i<V;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        safe.push_back(node);
        for(auto parent:rev[node])
        {
            indegree[parent]--;
            if(indegree[parent] == 0)
            {
                q.push(parent);
            }
        }
    }
    sort(safe.begin(), safe.end());
    return safe;
}
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3},{1,4},{2,3},{3,4}};
    vector<int> ans = safeNodes(V, edges);
    for(int x : ans) cout << x << " ";
    return 0;
}
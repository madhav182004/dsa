#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void topoBfs(int n, vector<int>& topo, unordered_map<int, list<int>>& adjList) {
    queue<int> q;
    unordered_map<int, int> indegree;
    for(auto i : adjList)
    {
        for(auto nbr : i.second)
        {
            indegree[nbr]++;
        }
    }
    for(int node = 0; node < n; node++)
    {
        if(indegree[node] == 0)
        {
            q.push(node);
        }
    }

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        topo.push_back(frontNode);
        for(auto nbr : adjList[frontNode]) 
        {
            indegree[nbr]--;
            if(indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
}
int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adjList;
    for(auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
    }
    vector<int> topo;
    topoBfs(V, topo, adjList);

    vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
    for(auto i : edges)
    {
        hasEdge[i[0]][i[1]] = true;
    }
    int count = 0;
    for(int i = 0; i < topo.size()-1; i++)
    {
        for(int j = i + 1; j < topo.size(); j++)
        {
            int u = topo[i];
            int v = topo[j];
            if(!hasEdge[u][v])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << maxEdgesToAdd(V, edges) << endl;
    return 0;
}
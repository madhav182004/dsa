#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

void topoSortBfs(int n, vector<int>& topo, unordered_map<int, list<int>>& adjList)
{
    queue<int> q;
    unordered_map<int, int> indegree;
    // Calculate indegrees
    for (auto i : adjList)
    {
        for (auto nbr : i.second)
        {
            indegree[nbr]++;
        }
    }
    // Initialize queue with nodes having 0 indegree
    for (int node = 0; node < n; node++)
    {
        if (indegree[node] == 0)
        {
            q.push(node);
        }
    }
    // BFS (Kahn's algorithm)
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        topo.push_back(frontNode);

        for (auto nbr : adjList[frontNode])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
}

vector<int> findOrder(int n, vector<vector<int>>& prerequisites)
{
    unordered_map<int, list<int>> adjList;
    // Building adjacency list
    for (vector<int> i : prerequisites)
    {
        int u = i[0];
        int v = i[1];
        adjList[v].push_back(u);
    }
    vector<int> topo;
    topoSortBfs(n, topo, adjList);

    // If topo sort includes all nodes then valid order
    if (topo.size() == n)
    {
        return topo;
    }
    else
    {
        return {}; // cycle present
    }
}

int main()
{
    int n, m;
    cout << "Enter number of courses (n): ";
    cin >> n;
    cout << "Enter number of prerequisite pairs (m): ";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for (int i = 0; i < m; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> order = findOrder(n, prerequisites);

    if (order.empty())
    {
        cout << "No valid course order (cycle detected).\n";
    }
    else
    {
        cout << "Course order: ";
        for (int x : order)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

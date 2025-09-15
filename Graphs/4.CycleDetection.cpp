#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList;
        void addEdge(T u, T v, bool direction)
        {
            if(direction == 1)
            {
                adjList[u].push_back(v);
            }
            else
            {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            printAdjList();
            cout<<endl;
        }
        void printAdjList()
        {
            for(auto i:adjList)
            {
                cout<<i.first<<": { ";
                for (auto nbr : i.second)
                {
                    cout << nbr << ", ";
                }
                cout<<" }"<<endl;
            }
        }
        bool checkCycleUndirectedBFS(T src)
        {
            queue<T> q;
            unordered_map<T, bool> vis;
            unordered_map<T, T> parent;

            q.push(src);
            vis[src] = true;
            parent[src] = -1;
            while(!q.empty())
            {
                T frontNode = q.front();
                q.pop();
                for(auto nbr:adjList[frontNode])
                {
                    if(!vis[nbr])
                    {
                        q.push(nbr);
                        vis[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    else if(vis[nbr] == true && nbr != parent[frontNode])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool checkCycleUndirectedDfs(T src, unordered_map<T, bool>& vis, int parent)
        {
            vis[src] = true;
            for(auto nbr:adjList[src])
            {
                if(!vis[nbr])
                {
                    bool ans = checkCycleUndirectedDfs(nbr, vis, src);
                    if(ans == true)
                    {
                        return true;
                    }
                }
                else if(vis[nbr] == 1)
                {
                    return true;
                }
            }
            return false;
        }
        bool checkCycleDirectedDfs(T src, unordered_map<T, bool>& vis, unordered_map<T, bool>& dfsTrack)
        {
            vis[src] = true;
            dfsTrack[src] = true;
            for(auto nbr:adjList[src])
            {
                if(!vis[nbr])
                {
                    bool ans = checkCycleDirectedDfs(nbr, vis, dfsTrack);
                    if(ans == true)
                    {
                        return true;
                    }
                }
                else if(vis[nbr] == true && dfsTrack[nbr] == true)
                {
                    return true;
                }
            }
            dfsTrack[src] = false; //imp backtracking
            return false;
        }
};
int main()
{
    // Graph<int> g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 5, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(3, 4, 0);
    // if(g.checkCycleUndirectedBFS(0))
    // {
    //     cout<<"Cycle Present"<<endl;
    // }
    // else
    // {
    //     cout<<"Cycle absent"<<endl;
    // }


    // unordered_map<int, bool> vis;
    // int parent = -1;
    // if(g.checkCycleUndirectedDfs(0, vis, parent))
    // {
    //     cout<<"Cycle Present"<<endl;
    // }
    // else
    // {
    //     cout<<"Cycle absent"<<endl;
    // }

    Graph<int> g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    // g.addEdge(4, 2, 1);
    g.addEdge(4, 5, 1);
    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfsTrack;
    if(g.checkCycleDirectedDfs(0, vis, dfsTrack))
    {
        cout<<"Cycle Present"<<endl;
    }
    else
    {
        cout<<"Cycle absent"<<endl;
    }
    return 0;
}
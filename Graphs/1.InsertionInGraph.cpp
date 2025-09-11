#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    public:
        unordered_map<T, list<pair<T, int>>> adjList;
        void addEdge(T u, T v, int wt, bool direction)
        {
            if(direction == 1)
            {
                adjList[u].push_back({v, wt});
            }
            else
            {
                adjList[u].push_back({v, wt});
                adjList[v].push_back({u, wt});
            }
            printAdjList();
            cout<<endl;
        }
        void printAdjList()
        {
            for(auto i:adjList)
            {
                cout<<i.first<<": { ";
                for(pair<T, T> p:i.second)
                {
                    cout<<"{ "<<p.first<<", "<<p.second<<"}, ";
                }
                cout<<" }"<<endl;
            }
        }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1);
    return 0;
}
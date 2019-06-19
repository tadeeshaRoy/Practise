//Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int v);
        void addEdge(int v, int w);
        void dfs(int v);
        void dfsUtil(int v, bool visited[]);
};

Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::dfsUtil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator i;

    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            dfsUtil(*i, visited);
    }
}

void Graph::dfs(int v)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    dfsUtil(v,visited);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.dfs(2); 
    return 0;
}

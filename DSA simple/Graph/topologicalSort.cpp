Reference: https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/


#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &s);

    public:
        Graph(int v);
        void addEdge(int v, int w);
        void topologicalSort();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalSort()
{
    bool *visited = new bool[v];

    stack<int> s;

    for(int i=0;i<v;i++)
        visited[v] = false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            topologicalSortUtil(i,visited,s);
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

void Graph::topologicalSortUtil(int v,bool visited[], stack<int> &s)
{
    visited[v] = true;

    list<int>::iterator i;

    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            topologicalSortUtil(*i,visited,s);
    }

    s.push(v);
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph n"; 
    g.topologicalSort(); 
  
    return 0;
}

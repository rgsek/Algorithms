// Author: Gnanasekar Rajakumar

#include <iostream>
#include <list>
#include <stack>

using namespace std;

#if 0
(0,3)
(0,1)
(1,2)
(1,0)
(2,4)
(3,4)
(4,5)
(5,4)


0------>3----->4------->5
|      |     |
|     |     | 
|    |     |
|   |     | 
|  |     |
| |     |
1----->2

Visiting order should be:
0 , 3, 4, 5, 1, 2

#endif


class Graph {
public:
    Graph(int vertices);
    void create_edge(int vertex1, int vertex2);
    void do_dfs(int start);
private:
    int m_vertices;
    list<int>* m_edges;
    void dfs_recurse(int vertex, int* visisted);
};

Graph::Graph(int vertices)
{
    m_edges = new list<int>[vertices];
    m_vertices = vertices;
}

//Recursion allows to go to the edge(depth) first.
void Graph::do_dfs(int start)
{
    int* visited = new int[m_vertices];

    for (int i = 0; i < m_vertices; i++)
        visited[i] = 0;

    dfs_recurse(start, visited);
}

void Graph::dfs_recurse(int start, int* visited)
{
    visited[start] = 1;
    cout << start << " ";
    for (list<int>::iterator i = m_edges[start].begin(); i != m_edges[start].end(); i++)
    {
        if (!visited[*i])
            dfs_recurse(*i, visited);
    }
}
void Graph::create_edge(int vertex1, int vertex2)
{
    m_edges[vertex1].push_back(vertex2);
}

// create a graph as shown in the header
int main(int argc, char** argv)
{
    Graph graph(6);
    graph.create_edge(0,3);
    graph.create_edge(0,1);
    graph.create_edge(1,2);
    graph.create_edge(1,0);
    graph.create_edge(2,4);
    graph.create_edge(3,4);
    graph.create_edge(4,5);
    graph.create_edge(5,5);

    graph.do_dfs(0);
    return 0;
}
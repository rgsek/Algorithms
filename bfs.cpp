// Author: Gnanasekar Rajakumar

#include <iostream>
#include <list>
#include <queue>

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
0 , 3, 1, 4, 2, 5

#endif


class Graph {
public:
    Graph(int vertices);
    void create_edge(int vertex1, int vertex2);
    void do_bfs(int start);
private:
    int m_vertices;
    list<int>* m_edges;
};

Graph::Graph(int vertices)
{
    m_edges = new list<int>[vertices];
    m_vertices = vertices;
}
// Key to bfs is that the immediate adjacent node has to be visted first. So traversal happens
// level by level. Queue is the key data structure here as it allows us to enqueue vertices at
// each level and pop them in the same order
void Graph::do_bfs(int start)
{
    int* visited = new int[m_vertices];

    for (int i = 0; i < m_vertices; i++)
        visited[i] = 0;

    queue<int> myqueue;
    visited[start] = 1;
    myqueue.push(start);

    while (!myqueue.empty())
    {
        int vertex = myqueue.front();
        cout << vertex << " ";
        myqueue.pop();
        visited[vertex] = 1;
        
        for (list<int>::iterator i = m_edges[vertex].begin(); i != m_edges[vertex].end(); i++)
        {
            if (!visited[*i])
            {
                myqueue.push(*i);
                //visited[*i] = 1;
            }
        }
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

    graph.do_bfs(0);
    return 0;
}
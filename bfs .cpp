#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100; // maximum number of vertices in the graph

int graph[MAX][MAX] = {
    {0, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0}}; // adjacency matrix representation of the graph

bool visited[MAX]; // array to keep track of visited vertices

void DFS(int v, int n)
{
    visited[v] = true; // mark vertex as visited
    cout << v << " ";  // visit the vertex

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
        { // if vertex is adjacent and not visited
            DFS(i, n); // recursively visit adjacent vertices
        }
    }
}

int main()
{
    int n = 6, start = 0; // n is number of vertices in the graph, start is the starting vertex

    memset(visited, false, sizeof(visited)); // initialize visited array to false
    cout << "DFS traversal: ";
    DFS(start, n);
    cout << endl;

    return 0;
}
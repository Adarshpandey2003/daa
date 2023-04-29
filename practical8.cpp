#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex) {
    visited[vertex] = true; // Mark the current vertex as visited
    cout << vertex << " "; // Print the current vertex

    // Visit all neighbors of the current vertex that have not been visited
    for (int i = 0; i < graph[vertex].size(); i++) {
        int neighbor = graph[vertex][i];
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    vector<bool> visited(numVertices, false); // Mark all vertices as unvisited

    dfs(graph, visited, startVertex); // Run DFS starting from the given vertex

    // Visit any remaining unvisited vertices in case the graph is not connected
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main() {
    // Define a graph using an adjacency list representation
    vector<vector<int>> graph = {
        {1, 2}, // 0th vertex has neighbors 1 and 2
        {0, 2, 3}, // 1st vertex has neighbors 0, 2, and 3
        {0, 1, 3, 4}, // 2nd vertex has neighbors 0, 1, 3, and 4
        {1, 2, 4}, // 3rd vertex has neighbors 1, 2, and 4
        {2, 3} // 4th vertex has neighbors 2 and 3
    };

    dfsTraversal(graph, 0); // Run DFS starting from vertex 0

    return 0;
}

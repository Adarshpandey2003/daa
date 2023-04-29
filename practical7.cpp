#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    vector<bool> visited(numVertices, false); // Mark all vertices as unvisited
    queue<int> q; // Initialize a queue for BFS

    visited[startVertex] = true; // Mark the starting vertex as visited
    q.push(startVertex); // Add the starting vertex to the queue

    while (!q.empty()) {
        int currVertex = q.front(); // Get the next vertex from the queue
        q.pop();

        cout << currVertex << " "; // Print the current vertex

        // Visit all neighbors of the current vertex that have not been visited
        for (int i = 0; i < graph[currVertex].size(); i++) {
            int neighbor = graph[currVertex][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    bfs(graph, 0); // Run BFS starting from vertex 0

    return 0;
}

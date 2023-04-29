#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100; // maximum number of nodes

// define the graph as an adjacency list using an array of linked lists
struct Node {
    int dest;
    Node* next;
};

Node* graph[MAXN]; // array of linked lists
bool visited[MAXN]; // array to mark visited nodes

// function to add an edge to the graph
void addEdge(int src, int dest) {
    Node* newNode = new Node;
    newNode->dest = dest;
    newNode->next = graph[src];
    graph[src] = newNode;
}

// BFS algorithm without using vector
void BFS(int start) {
    queue<int> q; // create an empty queue
    visited[start] = true; // mark the starting node as visited
    q.push(start); // enqueue the starting node
    while (!q.empty()) { // repeat until the queue is empty
        int curr = q.front(); // dequeue the node at the front of the queue
        q.pop();
        cout << curr << " "; // print the current node
        for (Node* ptr = graph[curr]; ptr != NULL; ptr = ptr->next) { // for each neighbor of the current node
            int next = ptr->dest;
            if (!visited[next]) { // if the neighbor is unvisited
                visited[next] = true; // mark the neighbor as visited
                q.push(next); // enqueue the neighbor
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // read the number of nodes and edges
    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest; // read an edge (src, dest)
        addEdge(src, dest); // add the edge to the graph
        addEdge(dest, src); // add the reverse edge as well for an undirected graph
    }
    int start;
    cin >> start; // read the starting node
    BFS(start); // run the BFS algorithm starting from the starting node
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair
#include <limits.h> // for INT_MAX

using namespace std;

typedef pair<int, int> pii; // A pair to represent a vertex and its distance

// Function to implement Dijkstra's algorithm
void dijkstra(int src, vector<vector<pii>>& graph, int V) {
    // Create a priority queue (min-heap) to store vertices and their distances
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize distances to all vertices as infinity (INT_MAX) and source distance as 0
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Push the source node into the priority queue with a distance of 0
    pq.push({0, src});

    // Process the graph
    while (!pq.empty()) {
        // Get the vertex with the smallest distance from the queue
        int u = pq.top().second;
        pq.pop();

        // Visit all the adjacent vertices of the current vertex 'u'
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path to 'v' is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the shortest distances from the source vertex
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Graph is represented as an adjacency list where each vertex has a list of pairs (neighbor, weight)
    vector<vector<pii>> graph(V);

    cout << "Enter edges (u, v, w) for each edge (source vertex, destination vertex, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // If the graph is undirected, add both directions
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Call Dijkstra's algorithm
    dijkstra(src, graph, V);

    return 0;
}

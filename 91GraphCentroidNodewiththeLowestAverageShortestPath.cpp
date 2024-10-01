#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <numeric>

using namespace std;

const int INF = numeric_limits<int>::max();

// Dijkstra's Algorithm to calculate shortest paths from a given node
vector<int> dijkstra(const unordered_map<int, vector<pair<int, int>>>& graph, int start, int n) {
    vector<int> distances(n, INF);
    distances[start] = 0;

    // Min-heap priority queue: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node])
            continue;

        for (auto& neighbor : graph.at(current_node)) {
            int next_node = neighbor.first;
            int edge_weight = neighbor.second;

            int new_distance = current_distance + edge_weight;
            if (new_distance < distances[next_node]) {
                distances[next_node] = new_distance;
                pq.push({new_distance, next_node});
            }
        }
    }

    return distances;
}

// Function to find the centroid of the graph
pair<int, double> find_graph_centroid(const unordered_map<int, vector<pair<int, int>>>& graph, int n) {
    double min_avg_distance = INF;
    int centroid = -1;

    // Iterate over each node to calculate the average shortest path from that node
    for (int node = 0; node < n; ++node) {
        vector<int> shortest_paths = dijkstra(graph, node, n);

        // Sum up the shortest paths
        int total_distance = 0;
        int reachable_nodes = 0;
        for (int dist : shortest_paths) {
            if (dist != INF) {
                total_distance += dist;
                reachable_nodes++;
            }
        }

        // Calculate average shortest path length, excluding the current node itself
        double avg_distance = static_cast<double>(total_distance) / (reachable_nodes - 1);

        // Update centroid if the average distance is smaller
        if (avg_distance < min_avg_distance) {
            min_avg_distance = avg_distance;
            centroid = node;
        }
    }

    return {centroid, min_avg_distance};
}

int main() {
    // Example graph (adjacency list): node -> [(neighbor, weight), ...]
    unordered_map<int, vector<pair<int, int>>> graph = {
        {0, {{1, 1}, {2, 2}}},
        {1, {{0, 1}, {3, 1}}},
        {2, {{0, 2}, {3, 3}}},
        {3, {{1, 1}, {2, 3}}}
    };

    int n = 4; // Number of nodes in the graph
    pair<int, double> result = find_graph_centroid(graph, n);

    cout << "Centroid: Node " << result.first << " with average shortest path length of " << result.second << endl;

    return 0;
}

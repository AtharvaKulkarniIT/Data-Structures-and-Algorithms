#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

bool bellmanFord(int n, vector<tuple<int, int, int>>& edges, int src, vector<int>& dist) {
    dist.assign(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect negative cycle
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w)
            return false; // Negative cycle
    }

    return true;
}

int main() {
    int n = 5;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, -3}, {1, 3, 7}, {2, 4, 3}, {3, 4, -1}
    };

    vector<int> dist;
    if (bellmanFord(n, edges, 0, dist)) {
        cout << "Bellman-Ford from 0:\n";
        for (int i = 0; i < n; ++i)
            cout << "Node " << i << " : " << dist[i] << endl;
    } else {
        cout << "Negative weight cycle detected!\n";
    }

    return 0;
}

/*
Time Complexity: O(V * E)
Space Complexity: O(V)
✅ Use : Single Source, negative edges, need to detect negative cycles
*/

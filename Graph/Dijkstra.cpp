#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int src, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 5; // vertices
    vector<vector<pair<int, int>>> adj(n);
    // u -> v with weight w
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    vector<int> dist;
    dijkstra(0, adj, dist);

    cout << "Dijkstra from 0:\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << " : " << dist[i] << endl;

    return 0;
}

/*
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
✅ Use : Single Source, no negative edges, fast for sparse graphs
*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();

    for (int k = 0; k < n; ++k) {      // Intermediate
        for (int i = 0; i < n; ++i) {  // Source
            for (int j = 0; j < n; ++j) {  // Destination
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize direct edges
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    dist[0][1] = 3;
    dist[0][2] = INF;
    dist[1][2] = 1;
    dist[2][3] = 2;
    dist[3][1] = -4;

    floydWarshall(dist);

    cout << "Floyd-Warshall:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: O(V^3)
Space Complexity: O(V^2)
✅ Use : Need all-pairs shortest paths, graph is small (~V <= 500)
*/

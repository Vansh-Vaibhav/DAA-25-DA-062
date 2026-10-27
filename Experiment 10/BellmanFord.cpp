#include <bits/stdc++.h>
using namespace std;
// Vansh Vaibhav 25/DA/062

struct Edge {
    int u, v, w;
};

int main() {
    int n = 5, m = 8;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0;

    cout << "Number of vertices: " << n << endl;
    cout << "Number of edges: " << m << endl;
    cout << "Edges (Source Destination Weight):" << endl;

    for (auto e : edges) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }

    cout << "Source vertex: " << src << endl;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    bool negCycle = false;

    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "\nNegative-weight cycle detected" << endl;
    } else {
        cout << "\nShortest distances from source " << src << ":" << endl;

        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << ": ";

            if (dist[i] == INT_MAX) {
                cout << "INF";
            } else {
                cout << dist[i];
            }

            cout << endl;
        }
    }

    cout << "Vansh Vaibhav 25/DA/062";

    return 0;
}
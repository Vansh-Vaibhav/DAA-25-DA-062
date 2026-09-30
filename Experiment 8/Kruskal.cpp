#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Initially, every vertex is its own set
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(), compare);

    int totalWeight = 0;
    int edgeCount = 0;

    cout << "Edges in MST:\n";

    for (Edge e : edges) {

        // If adding this edge doesn't create a cycle
        if (find(e.u) != find(e.v)) {

            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalWeight += e.weight;
            edgeCount++;

            unite(e.u, e.v);

            if (edgeCount == n - 1)
                break;
        }
    }

    cout << "Total weight = " << totalWeight<<endl;
    cout<<"VANSH VAIBHAV 25/DA/062";
    return 0;
}

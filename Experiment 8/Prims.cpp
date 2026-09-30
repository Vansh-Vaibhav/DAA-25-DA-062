#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int key[100];
    int parent[100];
    bool inMST[100];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {

        int u = -1;

        // Find vertex with minimum key
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !inMST[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "Total weight = " << totalWeight<<endl;
    cout << "VANSH VAIBHAV 25/DA/062\n";

    return 0;
}

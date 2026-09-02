#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);

    for (int i : adj[s]) {
        if (!visited[i]) {
            dfs(adj, visited, i, res);
        }
    }
}

vector<vector<int>> getComponents(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<vector<int>> res;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adj, visited, i, component);
            res.push_back(component);
        }
    }

    return res;
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 5, 4);

    vector<vector<int>> res = getComponents(adj);

    for (auto& component : res) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    cout<<"\nVansh Vaibhav 25/DA/062";
    return 0;
}

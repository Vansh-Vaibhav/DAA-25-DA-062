#include <bits/stdc++.h>
using namespace std;

int timer = 0;
vector<int> tin, low;
vector<bool> vis, ap;

void dfs(int u, int p, vector<vector<int>>& adj) {
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == p)
            continue;

        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, adj);
            low[u] = min(low[u], low[v]);

            if (p != -1 && low[v] >= tin[u])
                ap[u] = true;

            children++;
        }
    }

    if (p == -1 && children > 1)
        ap[u] = true;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tin.resize(n);
    low.resize(n);
    vis.assign(n, false);
    ap.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, -1, adj);
    }

    cout << "Articulation Points: ";

    for (int i = 0; i < n; i++) {
        if (ap[i])
            cout << i << " ";
    }
    cout<<"\nVansh Vaibhav CSDA 25/DA/062\n";
    return 0;
}

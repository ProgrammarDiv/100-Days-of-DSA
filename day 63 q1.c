#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ls;
    int vis[V] = {0}; 
    vector<int> ans = dfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

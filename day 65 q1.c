#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true)
                return true;
        }
        else if(adjacentNode != parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj))
                return true;
        }
    }
    return false;
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
    bool ans = isCycle(V, adj);
    if (ans) cout << "1";
    else cout << "0";
    return 0;
}

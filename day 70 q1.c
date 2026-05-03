#include <iostream>
#include <vector>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i = 0; i < V - 1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation to check for negative cycle
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }
    return dist;
}
int main() {
    int V, E, S;
    cin >> V >> E >> S;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> res = bellman_ford(V, edges, S);
    for (int i : res) cout << i << " ";
    return 0;
}

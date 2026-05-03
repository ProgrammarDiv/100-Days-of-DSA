#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    pq.push({0, S});
    
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];
            
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
int main() {
    int V, E, S;
    cin >> V >> E >> S;
    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected
    }
    vector<int> res = dijkstra(V, adj, S);
    for (int i : res) cout << i << " ";
    return 0;
}


































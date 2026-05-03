#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> res = topoSort(V, adj);
    for (int i : res) cout << i << " ";
    return 0;
}
⏱️ Complexity Analysis

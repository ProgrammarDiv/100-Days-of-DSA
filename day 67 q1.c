#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

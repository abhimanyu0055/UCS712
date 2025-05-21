#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<bool>& visited, stack<int>& st, const vector<vector<int>>& adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(V, false);
    stack<int> st;
    
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }

    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}
    };

    vector<int> sorted = topoSort(V, edges);
    for (int node : sorted) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

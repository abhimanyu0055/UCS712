#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int node, vector<bool>& visited, stack<int>& st, const vector<vector<int>>& adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, visited, st, adj);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<bool>& visited, const vector<vector<int>>& transpose) {
    visited[node] = true;
    for (int neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, visited, transpose);
        }
    }
}

int countSCCs(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    // Step 1: Fill the stack with nodes by finish time
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs1(i, visited, st, adj);
        }
    }

    // Step 2: Create the transpose graph
    vector<vector<int>> transpose(V);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }

    // Step 3: Do DFS on transposed graph to count SCCs
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            dfs2(node, visited, transpose);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 2}, {2, 1}, {1, 0}, {0, 3}, {3, 4}
    };

    int numSCCs = countSCCs(V, edges);
    cout << "Number of Strongly Connected Components: " << numSCCs << endl;

    return 0;
}

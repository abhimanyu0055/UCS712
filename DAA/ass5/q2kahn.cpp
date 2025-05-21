#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSortKahn(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // Build adjacency list and calculate indegrees
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++; // Count incoming edges
    }

    queue<int> q;
    // Push all nodes with 0 indegree
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--; // Remove edge
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycle
    if (result.size() != V) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return result;
}

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}
    };

    vector<int> sorted = topoSortKahn(V, edges);
    for (int node : sorted) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

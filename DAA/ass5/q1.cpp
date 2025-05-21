#include <iostream>
#include <vector>

using namespace std;

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

vector<int> path(V, -1);

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)          //edge
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamCycleUtil(pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

void printSolution() {
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;  // to show the cycle
}

void hamCycle() {
    path[0] = 0;

    if (hamCycleUtil(1) == false) {
        cout << "No Hamiltonian Cycle found\n";
        return;
    }

    printSolution();
}

int main() {
    hamCycle();
    return 0;
}

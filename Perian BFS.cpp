#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicBFS(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (adjMatrix[u][v])
                indegree[v]++;

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int i = 0; i < n; ++i) {
            if (adjMatrix[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
    }

    if (count != n) {
        cout << "Cycle detected (BFS - Kahn's Algorithm)" << endl;
        return true;
    } else {
        cout << "No cycle found (BFS - Kahn's Algorithm)" << endl;
        return false;
    }
}

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}  // Cycle exists: 0->1->2->0
    };

    isCyclicBFS(adjMatrix);
    return 0;
}
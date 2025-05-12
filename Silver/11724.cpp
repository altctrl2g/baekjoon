#include <iostream>
#include <vector>
using namespace std;

void DFS(int vertex, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[vertex] = true;

    for (int i : adjList[vertex]) {
        if (visited[i] == false) {
            DFS(i, adjList, visited);
        }
    }
}

int main() {


    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n+1);
    vector<bool> visited(n+1, false);

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int count = 0;

    for (int i=1; i<n+1; i++) {
        if (visited[i] == false) {
            DFS(i, adjList, visited);
            count++;
        }
    }

    cout << count;

    return 0;
}
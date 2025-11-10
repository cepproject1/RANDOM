#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10  // Maximum number of locations (nodes)

// ---------- DFS using Adjacency Matrix ----------
void DFS(int node, int visited[], int adjMatrix[MAX][MAX], int n) {
    cout << char('A' + node) << " ";
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            DFS(i, visited, adjMatrix, n);
        }
    }
}

// ---------- BFS using Adjacency List ----------
void BFS(int start, vector<vector<int>> &adjList, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << char('A' + node) << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// ---------- Main Function ----------
int main() {
    int n; // Number of locations (nodes)
    cout << "Enter number of locations (nodes): ";
    cin >> n;

    int adjMatrix[MAX][MAX] = {0};
    vector<vector<int>> adjList(n);

    int edges;
    cout << "Enter number of routes (edges): ";
    cin >> edges;

    cout << "Enter each connection (e.g., A B means route between A and B):\n";
    for (int i = 0; i < edges; i++) {
        char u, v;
        cin >> u >> v;
        int a = u - 'A';
        int b = v - 'A';
        
        // For adjacency matrix (undirected graph)
        adjMatrix[a][b] = adjMatrix[b][a] = 1;

        // For adjacency list
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int start = 0; // Starting from A (you can change if needed)
    cout << "\nDFS Traversal (using Adjacency Matrix): ";
    int visited[MAX] = {0};
    DFS(start, visited, adjMatrix, n);

    cout << "\nBFS Traversal (using Adjacency List): ";
    BFS(start, adjList, n);

    cout << endl;
    return 0;
}

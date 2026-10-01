#include <iostream>
using namespace std;

int a[100][100], vis[100], n;

void dfs(int u) {
    vis[u] = 1;
    cout << u << " ";

    for (int v = 0; v < n; v++) {
        if (a[u][v] && !vis[v])
            dfs(v);
    }
}

int main() {
    int e, u, v, s;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> s;

    cout << "DFS = ";
    dfs(s);

    return 0;
}

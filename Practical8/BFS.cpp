#include <iostream>
using namespace std;

int a[100][100], vis[100], q[100];

int main() {
    int n, e, u, v, s;
    
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

    int f = 0, r = 0;
    q[r++] = s;
    vis[s] = 1;

    cout << "BFS = ";

    while (f < r) {
        u = q[f++];
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (a[u][v] && !vis[v]) {
                vis[v] = 1;
                q[r++] = v;
            }
        }
    }

    return 0;
}

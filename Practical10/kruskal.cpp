#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, e;
    cin >> n >> e;

    Edge edges[100];

    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges, edges + e, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;

    for (int i = 0; i < e; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            parent[a] = b;
            cost += edges[i].w;
            cout << edges[i].u << " - " << edges[i].v
                 << " : " << edges[i].w << endl;
        }
    }

    cout << "Total cost: " << cost;
    return 0;
}

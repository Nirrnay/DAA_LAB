#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int visited[10] = {0};
    visited[0] = 1;
    int cost = 0;

    for (int k = 0; k < n - 1; k++) {
        int min = 9999, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && a[i][j] != 0 && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v == -1) break;

        visited[v] = 1;
        cost += min;
        cout << u << " - " << v << " : " << min << endl;
    }

    cout << "Total cost: " << cost;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> m;

    int profit[n], weight[n];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int dp[n + 1][m + 1];

    // Initialize first row and first column with 0
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    // Dynamic Programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (weight[i - 1] <= j) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]]
                );
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][m];

    return 0;
}

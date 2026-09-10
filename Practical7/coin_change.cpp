#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n];

    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter the amount: ";
    cin >> amount;

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    cout << "Minimum number of coins: " << dp[amount];

    return 0;
}

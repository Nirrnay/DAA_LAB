
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int path[10];

    for(int i = 0; i < n; i++)
    {
        path[i] = i;
    }

    int minCost = 99999;

    do
    {
        int totalCost = 0;

        for(int i = 0; i < n - 1; i++)
        {
            totalCost += cost[path[i]][path[i+1]];
        }

        totalCost += cost[path[n-1]][path[0]];

        if(totalCost < minCost)
        {
            minCost = totalCost;
        }

    } while(next_permutation(path + 1, path + n));

    cout << "\nMinimum Travelling Cost: " << minCost;

    return 0;
}

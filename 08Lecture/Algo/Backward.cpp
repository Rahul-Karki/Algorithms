#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 8; 

    int cost[8][8] = {
        {0, 2, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 2, 0, 0, 0},
        {0, 0, 0, 2, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int minCost[8];
    int decision[8]; 

    minCost[n-1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        minCost[i] = INT_MAX;

        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0) {
                if (cost[i][j] + minCost[j] < minCost[i]) {
                    minCost[i] = cost[i][j] + minCost[j];
                    decision[i] = j;
                }
            }
        }
    }

    cout << "Minimum cost: " << minCost[0] << endl;

    cout << "Path: ";
    int i = 0;
    while (i != n - 1) {
        cout << i << " -> ";
        i = decision[i];
    }
    cout << n - 1 << endl;

    return 0;
}
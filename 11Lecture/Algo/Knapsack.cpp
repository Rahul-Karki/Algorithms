#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

void displayDPTable(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nDP Table:\n";
    cout << "Capacity: ";
    for (int w = 0; w <= capacity; w++) {
        cout << w << "\t";
    }
    cout << "\n";
    
    for (int i = 0; i <= n; i++) {
        cout << "Item " << i << ": ";
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << "\n";
    }
}

void findItemsIncluded(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nItems included in optimal solution:\n";
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << ": Weight = " << weights[i - 1] 
                 << ", Value = " << values[i - 1] << "\n";
            w -= weights[i - 1];
        }
    }
}

int main() {
    cout << "=== 0/1 Knapsack Problem using Dynamic Programming ===\n\n";
    
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 8;
    
    cout << "Example 1:\n";
    cout << "Items: 4\n";
    cout << "Weights: ";
    for (int w : weights) cout << w << " ";
    cout << "\nValues: ";
    for (int v : values) cout << v << " ";
    cout << "\nCapacity: " << capacity << "\n";
    
    int maxValue = knapsack01(weights, values, capacity);
    cout << "Maximum value that can be obtained: " << maxValue << "\n";
    
    displayDPTable(weights, values, capacity);
    findItemsIncluded(weights, values, capacity);
    cout << "\n\n=== Example 2 ===\n";
    vector<int> weights2 = {1, 2, 3, 4};
    vector<int> values2 = {5, 4, 8, 6};
    int capacity2 = 5;
    
    cout << "Items: 4\n";
    cout << "Weights: ";
    for (int w : weights2) cout << w << " ";
    cout << "\nValues: ";
    for (int v : values2) cout << v << " ";
    cout << "\nCapacity: " << capacity2 << "\n";
    
    int maxValue2 = knapsack01(weights2, values2, capacity2);
    cout << "Maximum value that can be obtained: " << maxValue2 << "\n";
    
    displayDPTable(weights2, values2, capacity2);
    findItemsIncluded(weights2, values2, capacity2);
    
    return 0;
}

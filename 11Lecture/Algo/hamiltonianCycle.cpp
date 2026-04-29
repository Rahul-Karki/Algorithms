#include <iostream>
#include <vector>
using namespace std;

void nextValue(int k, vector<vector<int>> &graph, vector<int> &x, int n) {
    while (true) {
        x[k] = (x[k] + 1) % n;

        if (x[k] == 0)
            return;

        if (graph[x[k - 1]][x[k]] == 1) {
            int j;
            for (j = 0; j < k; j++) {
                if (x[j] == x[k])
                    break;
            }

            if (j == k) {
                if (k < n - 1 || (k == n - 1 && graph[x[k]][x[0]] == 1)) {
                    return;
                }
            }
        }
    }
}

void hamiltonian(int k, vector<vector<int>> &graph, vector<int> &x, int n) {
    while (true) {
        nextValue(k, graph, x, n);

        if (x[k] == 0)
            return;

        if (k == n - 1) {
            for (int i = 0; i < n; i++)
                cout << x[i] << " ";
            cout << x[0] << endl; 
        } else {
            hamiltonian(k + 1, graph, x, n);
        }
    }
}

int main() {
    int n;

    cout << "Enter number of vertices (n): ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> x(n, 0);
    x[0] = 0; // starting vertex

    cout << "Hamiltonian Cycles:\n";
    hamiltonian(1, graph, x, n);

    return 0;
}
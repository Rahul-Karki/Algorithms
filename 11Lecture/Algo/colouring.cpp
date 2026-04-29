#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, int c, vector<vector<int>> &graph, vector<int> &color, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

void solve(int v, vector<vector<int>> &graph, vector<int> &color, int n, int m) {
    if (v == n) {
        for (int i = 0; i < n; i++)
            cout << color[i] << " ";
        cout << endl;
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, graph, color, n)) {
            color[v] = c;
            solve(v + 1, graph, color, n, m);
            color[v] = 0; 
        }
    }
}

int main() {
    int n, m;

    cout << "Enter number of vertices (n): ";
    cin >> n;

    cout << "Enter number of colors (m): ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> color(n, 0);

    cout << "Valid colorings:\n";
    solve(0, graph, color, n, m);

    return 0;
}
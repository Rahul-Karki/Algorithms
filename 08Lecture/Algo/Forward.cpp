#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1);

    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(cost[i][j] != 0 && dist[j] > dist[i] + cost[i][j]) {
                dist[j] = dist[i] + cost[i][j];
                parent[j] = i;
            }
        }
    }

    cout << dist[n] << endl;

    vector<int> path;
    int curr = n;
    while(curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    for(int x : path) cout << x << " ";

    return 0;
}
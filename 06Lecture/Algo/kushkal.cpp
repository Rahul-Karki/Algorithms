#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<int> parent;

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) return;

    if (parent[px] < parent[py]) {
        parent[px] += parent[py];
        parent[py] = px;
    } else {
        parent[py] += parent[px];
        parent[px] = py;
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.w < b.w;
    });

    parent.assign(n, -1);

    int mincost = 0, count = 0;

    for (auto &e : edges) {
        int u = e.u, v = e.v;

        if (find(u) != find(v)) {
            unionSet(u, v);
            mincost += e.w;
            count++;

            cout << u << " - " << v << endl;

            if (count == n - 1) break;
        }
    }

    if (count != n - 1) {
        cout << "No Spanning Tree" << endl;
        return -1;
    }

    return mincost;
}

int main() {
    int n = 5;

    vector<Edge> edges;
    edges.emplace_back(0,1,2);
    edges.emplace_back(0,3,6);
    edges.emplace_back(1,2,3);
    edges.emplace_back(1,3,8);
    edges.emplace_back(1,4,5);
    edges.emplace_back(2,4,7);
    edges.emplace_back(3,4,9);

    int cost = kruskal(n, edges);
    cout << "MST Cost: " << cost << endl;
}
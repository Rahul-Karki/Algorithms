#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int cnt;

void solve(int s, int k, int r, vector<int> &w, vector<int> &x, int n, int W) {
    if (k < n) {
        x[k] = 1;

        if (s + w[k] == W) {
            cnt++;
        }
        else if (k + 1 < n && s + w[k] + w[k + 1] <= W) {
            solve(s + w[k], k + 1, r - w[k], w, x, n, W);
        }

        if (k + 1 < n && s + r - w[k] >= W && s + w[k + 1] <= W) {
            x[k] = 0;
            solve(s, k + 1, r - w[k], w, x, n, W);
        }
    }
}

double getTime(vector<int> &w, int W) {
    int n = w.size();
    vector<int> x(n, 0);
    cnt = 0;

    int r = 0;
    for (int i = 0; i < n; i++) r += w[i];

    auto t1 = chrono::high_resolution_clock::now();
    solve(0, 0, r, w, x, n, W);
    auto t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> d = t2 - t1;
    return d.count();
}

vector<int> gen(int n) {
    vector<int> w(n);
    for (int i = 0; i < n; i++) w[i] = rand() % 10 + 1;
    sort(w.begin(), w.end());
    return w;
}

int main() {
    srand(time(0));

    int t, rep, W;

    cout << "enter number of sizes: ";
    cin >> t;

    vector<int> sizes(t);
    cout << "enter sizes:\n";
    for (int i = 0; i < t; i++) cin >> sizes[i];

    cout << "enter target sum: ";
    cin >> W;

    cout << "enter repetitions: ";
    cin >> rep;

    for (int n : sizes) {
        double avg = 0;

        for (int i = 0; i < 3; i++) getTime(gen(n), W);

        for (int i = 0; i < rep; i++) {
            vector<int> w = gen(n);
            avg += getTime(w, W);
        }

        cout << avg / rep << ", ";
    }

    return 0;
}
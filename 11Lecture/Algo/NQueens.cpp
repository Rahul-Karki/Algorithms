#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;

int solutions;

bool isSafe(int k, int i, vector<int> &x) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void solve(int k, vector<int> &x, int n) {
    if (k == n) {
        solutions++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(k, i, x)) {
            x[k] = i;
            solve(k + 1, x, n);
        }
    }
}

double timeTaken(int n) {
    vector<int> x(n, 0);
    solutions = 0;

    auto t1 = chrono::high_resolution_clock::now();
    solve(0, x, n);
    auto t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = t2 - t1;
    return duration.count(); // in milliseconds
}

int main() {
    int testCases, repetitions;

    cout << "Enter number of different n values: ";
    cin >> testCases;

    vector<int> sizes(testCases);

    cout << "Enter values of n:\n";
    for (int i = 0; i < testCases; i++) {
        cin >> sizes[i];
    }

    cout << "Enter number of repetitions for averaging: ";
    cin >> repetitions;

    cout << "\nAverage Time (ms) for each n:\n";

    for (int n : sizes) {
        double avg = 0;

        for (int i = 0; i < repetitions; i++) {
            avg += timeTaken(n);
        }

        cout << "n = " << n << " -> " << (avg / repetitions)
             << " ms, Solutions = " << solutions << endl;
    }

    return 0;
}
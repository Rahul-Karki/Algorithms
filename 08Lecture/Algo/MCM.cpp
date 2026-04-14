#include <bits/stdc++.h>
using namespace std;

void matrixChainMultiplication(vector<int> &p, int n) {
    int m[n][n];

    int s[n][n];


    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }


    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "\nM Matrix (Minimum Scalar Multiplications):\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j < i)
                cout << "0\t";
            else
                cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nS Matrix (Split Points k):\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j <= i)
                cout << "0\t";
            else
                cout << s[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<int> p = {10, 20, 30, 40, 30};

    int n = p.size();

    matrixChainMultiplication(p, n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int mx = INT_MIN;
int mn = INT_MAX;

void maxmin(vector<int>& arr, int s, int e) {
    if (s == e) {
        mx = mn = arr[s];
        return;
    }
    else if (e == s + 1) {
        if (arr[s] < arr[e]) {
            mn = arr[s];
            mx = arr[e];
        } else {
            mn = arr[e];
            mx = arr[s];
        }
        return;
    }

    int mid = s + (e - s) / 2;

    maxmin(arr, s, mid);
    int leftMin = mn;
    int leftMax = mx;

    maxmin(arr, mid + 1, e);
    int rightMin = mn;
    int rightMax = mx;

    mn = min(leftMin, rightMin);
    mx = max(leftMax, rightMax);
}

int main() {
    vector<int> arr = {1,2,3,-4,25,6,7,8,9,0};
    maxmin(arr, 0, arr.size() - 1);
    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;
}
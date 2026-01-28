#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

bool linearSearch(int arr[], int n, int target, int index) {
    if (index >= n) {
        return false;
    }
    if (arr[index] == target) {
        return true;
    }
    return linearSearch(arr, n, target, index + 1);
}

int getAverageTime(int n) {
    int total_diff = 0;
    int arr[10000];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        int target = rand();

        auto x = high_resolution_clock::now();
        linearSearch(arr, n, target, 0);
        auto y = high_resolution_clock::now();

        total_diff += duration_cast<nanoseconds>(y - x).count() ;
    }
    return total_diff / 100;
}

int main() {
    for (int i = 1000; i <= 10000; i += 1000) {
        int avg_time = getAverageTime(i);
        cout << "For size " << i << " the average time taken was " << avg_time << " ns" << endl;
    }
    return 0;
}
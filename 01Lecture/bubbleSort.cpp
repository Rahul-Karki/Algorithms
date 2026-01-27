#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void fill(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void bubbleSortRecursive(int arr[], int n) {
    if (n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSortRecursive(arr, n - 1);
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
        bubbleSortRecursive(arr, n);
        auto y = high_resolution_clock::now();

        total_diff += duration_cast<microseconds>(y - x).count() ;
    }
    return total_diff / 100;
}

int main() {
    for (int i = 100; i <= 1000; i += 100) {
        int avg_time = getAverageTime(i);
        cout << "For size " << i << " the average time taken was " << avg_time << " ms" << endl;
    }

    return 0;
}
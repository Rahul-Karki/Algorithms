#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void swapIndex(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int minIndex(int arr[], int i, int n) {
    int min = i;
    for (int j = i; j < n; j++) {
        if (arr[min] > arr[j]) min = j;
    }
    return min;
}

void selectionSort(int arr[], int i, int n) {
    if (i == n) return;
    int index = minIndex(arr, i, n);
    swapIndex(arr, index, i);
    selectionSort(arr, i + 1, n);
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
        selectionSort(arr, 0, n);
        auto y = high_resolution_clock::now();

        total_diff += duration_cast<microseconds>(y - x).count() ;
    }
    return total_diff / 100;
}

int main() {
    for (int i = 1000; i <= 10000; i += 1000) {
        int avg_time = getAverageTime(i);
        cout << "For size " << i << " the average time taken was " << avg_time << " ms" << endl;
    }

    return 0;
}
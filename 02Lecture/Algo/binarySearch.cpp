#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

int getAverageTime(int n) {
    long long total_diff = 0;
    int arr[10000];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000;
        }

        sort(arr, arr + n);

        int target = rand() % 10000;

        auto start = high_resolution_clock::now();
        binarySearch(arr, 0, n - 1, target);
        auto end = high_resolution_clock::now();

        total_diff += duration_cast<nanoseconds>(end - start).count();
    }

    return total_diff / 100;
}

int main() {
    for (int i = 1000; i <= 9000; i += 1000) {
        int time = getAverageTime(i);
        cout << "For " << i << " elements, time = "
             << time << " ns" << endl;
    }
    return 0;
}

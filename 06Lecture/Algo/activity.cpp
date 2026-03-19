#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool activityCompare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void printMaxActivities(Activity arr[], int n) {
    sort(arr, arr + n, activityCompare);

    cout << "Selected activities are:\n";

    int lastFinish = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << "(" << arr[i].start << ", " << arr[i].finish << ") ";
            lastFinish = arr[i].finish;
        }
    }
    cout << "\n";
}

int main() {
    Activity arr[] = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);

    printMaxActivities(arr, n);

    return 0;
}
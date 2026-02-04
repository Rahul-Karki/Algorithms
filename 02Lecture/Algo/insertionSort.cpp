#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[],int& n,int i){
    if(i == n){
        return;
    }
    int j = i;
    int toBePlaced = arr[j];
    while(j > 0 ){
        if(arr[j-1] > toBePlaced){
            arr[j] = arr[j-1];
        }
        j--;
    }
    arr[j] = toBePlaced;
    
    insertionSort(arr,n,i+1);
}


int getAverageTime(int n) {
    int total_diff = 0;
    int arr[10000];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }

        auto x = high_resolution_clock::now();
        insertionSort(arr, n, 1);
        auto y = high_resolution_clock::now();

        total_diff += duration_cast<microseconds>(y - x).count() ;
    }
    return total_diff / 100;
}

int main() {
    for (int i = 1000; i < 10000; i += 1000) {
        int time = getAverageTime(i);
        cout << "For size " << i << " the average time taken was "<<time<< " ms" << endl;
    }

    return 0;
}
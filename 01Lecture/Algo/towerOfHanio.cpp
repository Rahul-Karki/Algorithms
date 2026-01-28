#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void towerOfHanoi(int n, char source, char dest, char helper) {
    if (n == 1) {
    //    cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n - 1, source, helper, dest);
    // cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, source);
}

long long int getAverageTime(int n) {
    long long int total_diff = 0;

    for(int i=0; i<5; i++){
         auto x = high_resolution_clock::now();
        towerOfHanoi(n, 'A', 'C', 'B');
        auto y = high_resolution_clock::now();

        total_diff += duration_cast<microseconds>(y - x).count() ;
    }
   
    
    return total_diff / 5;
}


int main() {
    for (int i = 15; i <= 25; i ++) {
        long long int avg_time = getAverageTime(i);
        cout << "For size " << i << " the average time taken was " << avg_time << " ms" << endl;
    }
   
    return 0;
}
#include <iostream>
using namespace std;

int power(int a, int n) {
    if (n == 0)
        return 1;

    return a * power(a, n - 1);
}

int main() {
    int a = 2, n = 5;
    cout<< "Power: "<<power(a, n)<< endl;
    return 0;
}

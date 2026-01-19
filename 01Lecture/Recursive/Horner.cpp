#include <iostream>
using namespace std;

int horner(int coeff[], int n, int x) {
    if (n == 1)
        return coeff[0];

    return coeff[0] * x + horner(coeff + 1, n - 1, x);
}

int main() {
    int coeff[] = {2, 3, 5, 7};
    int n = sizeof(coeff) / sizeof(coeff[0]);
    int x = 2;

    cout<<"Polynomial value: "<<horner(coeff, n, x)<<endl;
    return 0;
}

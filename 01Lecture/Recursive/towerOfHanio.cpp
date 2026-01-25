#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char helper) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n - 1, source, helper, dest);
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, source);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
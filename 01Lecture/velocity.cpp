#include <iostream>
using namespace std;

int jumps(double v, int t) {
    if (v >= 1) {
        t++;
        v = v - (0.425 * v);
        return jumps(v, t);
    } else {
        return t;
    }
}

int main() {
   cout<<jumps(40, 0)<<endl;
    return 0;
}
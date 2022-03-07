#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int gkq, ck, a, b;
    cin >> gkq >> ck;
    a = (gkq + ck) / 2;
    b = gkq - a;
    if (gkq < ck || abs(a - b) != ck)
        cout << -1;
    else
        cout << max(a, b) << " " << min(a, b);

    return 0;
}
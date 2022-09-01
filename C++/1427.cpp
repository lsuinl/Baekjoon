#include <iostream>

using namespace std;

int suin(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << suin(a, b) << endl << (a * b) / suin(a, b);
    return 0;
}
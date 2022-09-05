#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int sum, minus, a, b;
    cin >> sum >> minus;
    a = (sum + minus) / 2;
    b = sum - a;
    if (sum < minus || abs(a - b) != minus)
        cout << -1;
    else
        cout << max(a, b) << " " << min(a, b);

    return 0;
}
#include <iostream>

using namespace std;

int suin(int a, int b)
{
    if (b == 1) //1호의 경우 모두 1
        return 1;
    if (a == 0) //0층의 경우 b호는 b
        return b;
    return (suin(a - 1, b) + suin(a, b - 1));  //재귀호출. 개천재아니여?
}

int main()
{
    int t, k, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k >> n;
        cout << suin(k, n) << endl;
    }
}
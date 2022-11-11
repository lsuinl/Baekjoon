#include <iostream>

using namespace std;

int main()
{
    int m, n, min = 0, sum = 0;
    cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        int check = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                check++;
            }
        }
        if (check == 2)
        {
            sum += i;
            if (min == 0)
                min = i;
        }
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << "\n"
             << min;
    return 0;
}
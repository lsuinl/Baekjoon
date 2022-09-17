#include <iostream>
#include <algorithm>

using namespace std;
int sorting(int a, int b)
{
    return a > b;
}

int main()
{
    int t, a[10];
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        for (int i = 0; i < 10; i++)
            cin >> a[i];
        sort(a, a + 10, sorting);
        cout << a[2]<<"\n";
    }
    return 0;
}
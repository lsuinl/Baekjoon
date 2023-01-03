#include <iostream>
#include <algorithm>
//완
using namespace std;

int main()
{
    int T;
    cin >> T;
    int suin[10001];
    fill(suin, suin+10001,false);

    for (int i = 2; i <= 10000; i++)
    {
        int check = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            { // 소수제크
                check++;
            }
        }
        if (check == 2) // check==2면 소수인거시다.
            suin[i] = true;
    }
    for (int i = 0; i < T; i++)
    {
        int n, p1, p2;
        cin >> n;
        for (int j = n / 2; j < n;j++)
        {
            if (suin[j] && suin[n - j])
            { // 둘다소수면.
                p2 = j;
                p1 = n - j;
                break;
            }
        }
        cout << p1 << " " << p2 << endl;
    }
    return 0;
}
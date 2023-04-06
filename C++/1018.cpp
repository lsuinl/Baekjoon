#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    char board[51][51];
    int count, min = 100;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int a = 0; a <= m - 8; a++)
    {
        for (int b = 0; b <= n - 8; b++)
        {
            count = 0;
            for (int i = a; i < a + 8; i++)
            {
                for (int j = b; j < b + 8; j++)
                {
                    if (i % 2 == 0)
                    {
                        if (j % 2 == 0)
                            count = board[i][j] == 'W' ? count + 1 : count; // 짝-짝=흰색
                        else
                            count = board[i][j] == 'B' ? count + 1 : count; // 짝-홀=검은색
                    }
                    else
                    {
                        if (j % 2 == 0)
                            count = board[i][j] == 'B' ? count + 1 : count; // 홀-짝=검은색
                        else
                            count = board[i][j] == 'W' ? count + 1 : count; // 짝-홀=흰색
                    }
                }
            }
            count = (64 - count) < count ? (64 - count) : count;
            if (min > count)
                min = count;
        }
    }
    cout << min;
    return 0;
}

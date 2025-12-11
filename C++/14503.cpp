#include <iostream>

using namespace std;
int room[51][51] = {
    0,
};
int cleaningCount = 0;
int n, m;
int forwards, r, c;

void cleaning(int x, int y)
{
    int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
    if (room[x][y] == 0)
    {
        room[x][y] = 2;
        cleaningCount++;
    }

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx > -1 && xx < n && yy > -1 && yy < m)
        { // 범위체크
            if (room[xx][yy] == 0)
            { // 청소할곳이 남아있는경우
                bool isGo = false;
                while (!isGo)
                {
                    forwards = (forwards - 1) == -1 ? 3 : (forwards - 1);
                    switch (forwards)
                    {
                    case 0: // 북
                        if (x - 1 > -1 && room[x - 1][y] == 0)
                        {
                            cleaning(x - 1, y);
                            isGo = true;
                        }
                        break;
                    case 1: // 동
                        if (y + 1 < m && room[x][y + 1] == 0)
                        {
                            cleaning(x, y + 1);
                            isGo = true;
                        }
                        break;
                    case 2: // 남
                        if (x + 1 < n && room[x + 1][y] == 0)
                        {
                            cleaning(x + 1, y);
                            isGo = true;
                        }
                        break;
                    case 3: // 서
                        if (y - 1 > -1 && room[x][y - 1] == 0)
                        {
                            cleaning(x, y - 1);
                            isGo = true;
                        }
                        break;
                    }
                }
                return;
            }
        }
    }
    // 후진
    switch (forwards)
    {
    case 0: // 북
        if (x + 1 < n && room[x + 1][y] != 1)
            cleaning(x + 1, y);
        break;
    case 1: // 동
        if (y - 1 > -1 && room[x][y - 1] != 1)
            cleaning(x, y - 1);
        break;
    case 2: // 남
        if (x - 1 > -1 && room[x - 1][y] != 1)
            cleaning(x - 1, y);
        break;
    case 3: // 서
        if (y + 1 < m && room[x][y + 1] != 1)
            cleaning(x, y + 1);
        break;
    default:
        return;
    }
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> forwards;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }

    cleaning(r, c);
    cout << cleaningCount;

    return 0;
}
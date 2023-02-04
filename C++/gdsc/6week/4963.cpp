#include <iostream>
#include <queue>
using namespace std;
//틀렸다.
int w, h;
int suin[50][50];
bool visited[50][50];

void check(int i, int j)
{
    visited[i][j] = 1; // 방문 체크
    queue<pair<int, int>> q;
    q.push({i, j});
    // 둘러싼 좌표
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        int dy[8] = {y - 1, y - 1, y - 1, y + 1, y + 1, y + 1, y, y};
        int dx[8] = {x, x + 1, x - 1, x, x + 1, x - 1, x - 1, x + 1};
        q.pop();
        for (int a = 0; a < 8; a++)
        {
            if ((dy[a] < h && dy[a] > -1) && (dx[a] < w && dx[a] > -1))
            {
                if (!visited[dy[a]][dx[a]] && suin[dy[a]][dx[a]] == 1)
                { // 방문하지 않은 땅.
                    visited[dy[a]][dx[a]] = true;
                    q.push({dy[a], dx[a]});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        int result = 0;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break; // 나가는 조건
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> suin[i][j];
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (suin[i][j] == 1 && visited[i][j] == 0)
                {
                    check(i, j);
                    result++;
                }
            }
        }

        cout << result<<"\n";
    }
    return 0;
}
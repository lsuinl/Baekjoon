#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Size;

int result[301][301];

void move(int x, int y, int goalxy[2])
{
        result[x][y]=1;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty())
        {
            int xx = q.front().first, yy = q.front().second;
            if(xx==goalxy[0]&&yy==goalxy[1]){
                cout<<result[goalxy[1]][goalxy[0]]-1<<'\n';
            }
            q.pop();
            int dx[8] = {xx + 2, xx + 2, xx + 1, xx + 1, xx - 1, xx - 1, xx - 2, xx - 2};
            int dy[8] = {yy + 1, yy - 1, yy + 2, yy - 2, yy + 2, yy - 2, yy - 1, yy + 1};
            for (int i = 0; i < 8; i++)
            {
                if ((dx[i] < Size && dx[i] > -1) && (dy[i] < Size && dy[i] > -1))
                {
                    if (result[dx[i]][dy[i]] == 0)
                    {
                        q.push({dx[i], dy[i]});
                        result[dx[i]][dy[i]]=result[xx][yy]+1;
                    }
                }
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false); // 입출력시간단축
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; // 테스트 획수
    for (int i = 0; i < t; i++)
    {
        int xy[2], goalxy[2];
        cin >> Size; // 크기
        cin >> xy[0] >> xy[1];         // 현재위치
        cin >> goalxy[0] >> goalxy[1]; // 목표위치
        for (int j = 0; j < Size; j++)
        { // 초기화
            fill(result[j], result[j] + Size, 0);
        }
        move(xy[0], xy[1], goalxy); // bfs
    }

    return 0;
}
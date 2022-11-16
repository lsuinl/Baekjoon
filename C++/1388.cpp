#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m, answer;
bool visited[51][51];
char suin[51][51];

int xx[4] = {0, 0, -1, 1};
int yy[4] = {-1, 1, 0, 0};

void widthBFS(int y, int x)
{
    visited[y][x] = 1;       // 해당 위치 방문함!
    queue<pair<int, int>> q; // int형 두개를 쌍으로 가지는 queue
    q.push(make_pair(y, x)); // x,y쌍을 q에 저장
    while (!q.empty())
    {
        y = q.front().first;  // y좌표 저장
        x = q.front().second; // x좌표 저장
        q.pop();              // 삭제
        if (suin[y][x] == '-')
        {
            for (int i = 2; i < 4; i++)
            {
                int ny = y + yy[i];
                int nx = x + xx[i];
                // 해당 값이 지정 좌표 범위안에 있는지를 검사
                if (ny >= 0 && nx >= 0 && nx < m && ny < n)
                {
                    if (suin[ny][nx] == '-' && visited[ny][nx] == 0)
                    {
                        q.push({ny, nx});    // 없으면 새롭게 검사시작
                        visited[ny][nx] = 1; // 방문체크
                    }
                }
            }
        }
    }
}

void heightBFS(int y, int x)
{
    visited[y][x] = 1;       // 해당 위치 방문함!
    queue<pair<int, int>> q; // int형 두개를 쌍으로 가지는 queue
    q.push(make_pair(y, x)); // x,y쌍을 q에 저장
    while (!q.empty())
    {
        y = q.front().first;     // y좌표 저장
        x = q.front().second;    // x좌표 저장
        q.pop();                 // 삭제
        for (int i = 0; i < 2; i++)
        {
            int ny = y + yy[i];
            int nx = x + xx[i];
            // 해당 값이 지정 좌표 범위안에 있는지 검사
            if (ny >= 0 && nx >= 0 && nx < m && ny < n)
            {
                if (suin[ny][nx] == '|' && visited[ny][nx] == 0)
                {
                    q.push({ny, nx});    // 없으면 새롭게 검사시작
                    visited[ny][nx] = 1; // 방문체크
                }
            }
        }
    }
}

int main()
{
    memset(visited, 0, sizeof(visited)); // 위와 같음
    cin >> n >> m;
    for (int i = 0; i < n; i++) //y
    {
        for (int j = 0; j < m; j++)//x
        {
            cin >> suin[i][j];
        }
    }
    for (int i = 0; i < n; i++) //y
    {
        for (int j = 0; j < m; j++) //x
        {
            if (visited[i][j] == 0)//y,x
            {
                if (suin[i][j] == '-') 
                    widthBFS(i, j);
                else
                    heightBFS(i, j);
                answer++;
            }
        }
    }
    cout << answer;

    return 0;
}
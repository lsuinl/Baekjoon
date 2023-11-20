#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101] = {
    0,
};
bool visited[101][101];
int m, n, k;
vector<int> result;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int i, int j)
{
    for (int a = 0; a < 4; a++)
    {
        int x = i + dx[a];
        int y = j + dy[a];
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            if (map[x][y] == 0 && visited[x][y] == false)
            {
                result.back()+=1;
                visited[x][y] = true;
                DFS(x, y);
            }
        }
    }
}

int main()
{
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int firstx, firsty, secondx, secondy;
        cin >> firstx >> firsty >> secondx >> secondy;
        for (int x = firstx; x < secondx; x++)
        {
            for (int y = firsty; y < secondy; y++)
            {
                map[x][y] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && visited[i][j] == false)
            {
                visited[i][j] = true;
                result.push_back(1);
                DFS(i, j);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<<" ";
    }
    return 0;
}
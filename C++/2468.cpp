#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

using namespace std;

int ground[101][101];
bool visited[101][101];
int limit = 0;
int n;
int result[101];
vector<vector<int>> check = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void DFS(int i, int j)
{
    for (int a = 0; a < check.size(); a++)
    {
        int x = i + check[a][0];
        int y = j + check[a][1];
        if (x >= 0 && x < n && y >= 0 && y < n)
        {
            if (ground[x][y] > limit && visited[x][y]==false)
            {
                visited[x][y] = true;
                DFS(x, y);
            }
        }
    }
}

int main()
{
    set<int> number={0};
    int max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ground[i][j];
            number.insert(ground[i][j]);
        }
    }
    for(set<int>::iterator a = number.begin(); a != number.end(); a++)
    {
        limit = *a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ground[i][j] > limit && visited[i][j] == false)
                {
                    visited[i][j] = true;
                    result[limit]++;
                    DFS(i, j);
                }
            }
        }
        max = result[limit] > max ? result[limit] : max;
        memset(visited, false, sizeof(visited));
    }
    cout << max;
    return 0;
}
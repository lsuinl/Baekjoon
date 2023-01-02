#include <iostream>

using namespace std;

int main()
{
    int T, x1, y1, r1, x2, y2, r2;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int result = 0;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2)
        { // 무한대인경우 -1
            cout << -1 << endl;
            continue;
        }
        // 가장 끝 꼭짓점 4개 저장1번원
        int square2[4][2] = {{x2 - r2, y2}, {x2, y2 + r2}, {x2 + r2, y2}, {x2, y2 - r2}};
        ; // 2번원
        for (int j = 0; j < 4; j++)
        {
            int x = square2[j][0]; // 2번원의 꼭짓점
            int y = square2[j][1];
            if (x >= x1 - r1 && x <= x1 &&
                y >= y1 && y <= y1 + r1)
            {
                for (int z = 0; z < r1 + 1; z++)
                { // 해당 면의 1번원의 선과 꼭짓점과의 관계찾기
                    int xx = x1 - z;
                    int yy = y1 + (r1 - z);
                    if (xx == x && yy == y)
                    { // 선에 위치.
                        result++;
                        break;
                    }
                    else if (xx > x && yy < y)
                    { // 범위밖
                        break;
                    }
                    if (z == r1)
                    { // 범위 안
                        result = 2;
                    }
                }
            }
            else if (x >= x1 && x <= x1 + r1 &&
                    y >= y1 && y <= y1 + r1)
            {
                for (int z = 0; z < r1 + 1; z++)
                {
                    int xx = x1 + z;
                    int yy = y1 + (r1 - z);
                    if (xx == x && yy == y)
                    { // 선에 위치.
                        result++;
                        break;
                    }
                    else if (xx < x && yy < y)
                    { // 범위밖
                        break;
                    }

                    if (z == r1)
                    { // 범위 안
                        result = 2;
                    }
                }
            }
            else if (x >= x1 - r1 && x <= x1 &&
                    y >= y1 - r1 && y <= y1)
            {
                for (int z = 0; z < r1 + 1; z++)
                {
                    int xx = x1 - z;
                    int yy = y1 - (r1 + z);
                    if (xx == x && yy == y)
                    { // 선에 위치.
                        result++;
                        break;
                    }
                    else if (xx > x && yy > y)
                    { // 범위밖
                        break;
                    }

                    if (z == r1)
                    { // 범위 안
                        result = 2;
                    }
                }
            }
            else if (x >= x1 && x <= x1 + r1 &&
                    y >= y1 - r1 && y <= y1)
            {
                for (int z = 0; z < r1 + 1; z++)
                {
                    int xx = x1 + z;
                    int yy = y1 - (r1 + z);
                    if (xx == x && yy == y)
                    { // 선에 위치.
                        result++;
                        break;
                    }
                    else if (xx < x && yy > y)
                    { // 범위밖
                        break;
                    }

                    if (z == r1)
                    { // 범위 안
                        result = 2;
                    }
                }
            }
            if (result > 3)
            {
                result = 0;
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}

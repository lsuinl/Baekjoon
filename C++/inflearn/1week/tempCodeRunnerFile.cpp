// #include <iostream>

// using namespace std;

// int main()
// {
//     // W=땅의 전체 가로길이 , H=땅의 전체 세로길이, T=오렌지 나무 개수, S=땅 크기
//     int W, H, T, S;
//     cin >> W >> H >> T >> S;

//     int xy[T][2];
//     for (int i = 0; i < T; i++)
//     {
//         cin >> xy[i][0] >> xy[i][1];
//         // 개별 나무들을 꼭짓점으로 하여 4분면을 검사. 가장 많은 오렌지나무가 범위안에 있는 곳이 정답
//         int result = 0;

//         for (int i = 0; i < T; i++)
//         {
//             int plus[4] = {0, 0, 0, 0};

//             int maxx = xy[i][0] + S > W ? W : xy[i][0] + S; // x덧셈
//             int minx = xy[i][0] - S < 0 ? 0 : xy[i][0] - S; // x뺄셈
//             int maxy = xy[i][1] + S > H ? H : xy[i][1] + S; // y덧셈
//             int miny = xy[i][1] - S < 0 ? 0 : xy[i][1] - S; // y뺄셈

//             for (int j = 0; j < T; j++)
//             {
//                 // 1사분면
//                 if ((xy[j][0] <= xy[i][0] && xy[j][0] >= minx) &&
//                     (xy[i][1] <= xy[j][1] && maxy >= xy[j][1]))
//                     plus[0]++;
//                 // 2사분면
//                 if ((xy[j][0] >= xy[i][0] && xy[j][0] <= maxx) &&
//                     (xy[i][1] <= xy[j][1] && maxy >= xy[j][1]))
//                     plus[1]++;
//                 // 3사분면
//                 if ((xy[j][0] <= xy[i][0] && xy[j][0] >= minx) &&
//                     (xy[i][1] >= xy[j][1] && miny <= xy[j][1]))
//                     plus[2]++;
//                 // 4사분면
//                 if ((xy[j][0] >= xy[i][0] && xy[j][0] <= maxx) &&
//                     (xy[i][1] >= xy[j][1] && miny <= xy[j][1]))
//                     plus[3]++;
//             }
//             for (int j = 0; j < 4; j++)
//                 result = result > plus[j] ? result : plus[j];
//         }
//         cout << result;
//     }
//     return 0;
// }

#include <iostream>
#include <set>

using namespace std;

int main()
{
    // W=땅의 전체 가로길이 , H=땅의 전체 세로길이, T=오렌지 나무 개수, S=땅 크기
    int W, H, T, S;
    cin >> W >> H >> T >> S;

    int xy[T][2];
    set<int> xx;
    set<int> yy;
    for (int i = 0; i < T; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
        xx.insert(xy[i][0]);
        yy.insert(xy[i][1]);
        int len = yy.size() > xx.size() ? yy.size() : xx.size();
        int result = 0;

        for(int i:xx)
        {
            int maxx = i + S > W ? W : i + S;   // x덧셈
            for (int j:yy)
            {
                int plus=0;
                int maxy = j+ S > H ? H : j+ S; // y덧셈
                result = 0;
                for (int k = 0; k < T; k++)
                {
                    // 2사분면
                    if ((xy[k][0] >= i && xy[k][0] <= maxx) &&
                        (j <= xy[k][1] && maxy >= xy[k][1]))
                        plus++;
                }
                    result = result > plus ? result : plus;
            }
            cout << result;
        }
        return 0;
    }
}
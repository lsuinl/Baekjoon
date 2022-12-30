#include <iostream>

using namespace std;

int main()
{
    // W=땅의 전체 가로길이 , H=땅의 전체 세로길이, T=오렌지 나무 개수, S=땅 크기
    int W, H, T, S;
    cin >> W >> H >> T >> S;

    int xy[T][2];
    for (int i = 0; i < T; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
        // 개별 나무들을 꼭짓점으로 하여 4분면을 검사. 가장 많은 오렌지나무가 범위안에 있는 곳이 정답
        int result = 0;

        for (int i = 0; i < T; i++)
        {
            int max[4]; // x덧셈. x뺄셈, y덧셈, y뺄셈
            int suin[2] = {xy[i][0], xy[i][1]};

            int plus[4] = {0, 0, 0, 0};

            max[0] = suin[0] + S > W ? W : suin[0] + S; // x덧셈
            max[1] = suin[0] - S < 0 ? 0 : suin[0] - S; // x뺄셈
            max[2] = suin[1] + S > H ? H : suin[1] + S; // y덧ß셈
            max[3] = suin[1] - S < 0 ? 0 : suin[1] - S; // y뺄셈

            for (int j = 0; j < T; j++)
            {
                // 1사분면
                if ((xy[j][0] <= suin[0] && xy[j][0] >= max[1]) &&
                    (suin[1] <= xy[j][1] && max[2] >= xy[j][1]))
                    plus[0]++;
                // 2사분면
                if ((xy[j][0] >= suin[0] && xy[j][0] <= max[0]) &&
                    (suin[1] <= xy[j][1] && max[2] >= xy[j][1]))
                    plus[1]++;
                // 3사분면
                if ((xy[j][0] <= suin[0] && xy[j][0] >= max[1]) &&
                    (suin[1] >= xy[j][1] && max[3] <= xy[j][1]))
                    plus[2]++;
                // 4사분면
                if ((xy[j][0] >= suin[0] && xy[j][0] <= max[0]) &&
                    (suin[1] >= xy[j][1] && max[3] <= xy[j][1]))
                    plus[3]++;
            }

            for (int j = 0; j < 4; j++)
                result = result > plus[j] ? result : plus[j];
        }
        cout << result;
    }
    return 0;
}
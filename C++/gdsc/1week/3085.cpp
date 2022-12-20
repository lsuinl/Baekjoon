#include <iostream>
#include <vector>

using namespace std;

int N;
char candi[50][50];
int check(int i, int j)
{
    int result = 0;
    int source, suin;
    vector<char> forward;
    forward.push_back(candi[i][j]);
    if (i - 1 != -1)
        forward.push_back(candi[i - 1][j]);
    if (i + 1 != N)
        forward.push_back(candi[i + 1][j]);
    if (j - 1 != -1)
        forward.push_back(candi[i][j - 1]);
    if (j + 1 != N)
        forward.push_back(candi[i][j + 1]);
    // 처음색깔바꾼버전(가로편)
    for (int z = 0; z < forward.size(); z++)
    {
        suin = 1;
        source = forward[z];
        
        for (int a = j + 1; a < N; a++)
        { // 오른쪽 검사
            if (source == candi[i][a])
            {
                suin++;
            }
            else
                break;
        }
        for (int a = j -1; a < -1; a--)
        { // 왼쪽검사
            if (source == candi[i][a])
            {
                suin++;
            }
            else
                break;
        }
    }
    result = suin > result ? suin : result;
    // 처음색깔바꾼버전(세로편)
    for (int z = 0; z < forward.size(); z++)
    {
        suin = 1;
        source = forward[z];
        for (int a = i + 1; a < N; a++)
        { // 아래검사
            if (source == candi[a][j])
                suin++;
            else
                break;
        }
        for (int a = i -1; a < -1; a--)
        { // 위검사
            if (source == candi[a][j])
                suin++;
            else
                break;
        }
    }
    result = suin > result ? suin : result;
    cout << i << " " << j << " " << result << endl;
    return result;
}
// int check(int i, int j)
// {
//     int result = 0;
//     int source, suin;
//     vector<char> forward;
//     if (i - 1 != -1)
//         forward.push_back(candi[i - 1][j]);
//     if (i + 1 != N)
//         forward.push_back(candi[i + 1][j]);
//     if (j - 1 != -1)
//         forward.push_back(candi[i][j - 1]);
//     if (j + 1 != N)
//         forward.push_back(candi[i][j + 1]);

//     // 처음색깔바꾼버전(가로편)
//     for (int z = 0; z < forward.size(); z++)
//     {
//         suin = 1;
//         source = forward[z];
//         for (int a = j + 1; a < N; a++)
//         { // 가로줄검사
//             if (source == candi[i][a])
//             {
//                 suin++;
//             }
//             else
//                 break;
//         }
//     }
//     result = suin > result ? suin : result;
//     // 처음색깔바꾼버전(세로편)
//     for (int z = 0; z < forward.size(); z++)
//     {
//         suin = 1;
//         source = forward[z];
//         for (int a = i + 1; a < N; a++)
//         { // 세로줄검사
//             if (source == candi[a][j])
//                 suin++;
//             else
//                 break;
//         }
//     }
//     result = suin > result ? suin : result;
//     //--------------------------------
//     source = candi[i][j];
//     suin = 1;
//     bool jump = false;
//     for (int a = j + 1; a < N; a++)
//     { // 가로줄검사
//         if (source == candi[i][a])
//         {
//             suin++;
//         }
//         else if (!jump)
//         { // 다음숫자가 끝이 아니고, jump횟수도 없으먄
//             // cout<<i<<a<<"검사중.";
//             if (i + 1 != N)
//             { // 범위체크
//                 if (source == candi[i + 1][a])
//                 { // 주위에 날 구원할 같은 색이 존재하면
//                     jump = true;
//                     suin++;
//                 }
//             }
//             if (i - 1 != -1 && !jump)
//             { // 범위체크
//                 if (source == candi[i - 1][a])
//                 {
//                     jump = true;
//                     suin++;
//                 }
//             }
//             if (!jump) // 구원실패
//                 break;
//         }
//         else
//             break;
//     }
//     result = suin > result ? suin : result;
//     // 초기화
//     suin = 1;
//     jump = false;
//     for (int a = i + 1; a < N; a++)
//     { // 세로줄검사
//         if (source == candi[a][j])
//             suin++;
//         else if (!jump)
//         { // 다음숫자가 끝이 아니고, jump횟수도 없으먄
//             if (j + 1 != N)
//             { // 주위에 날 구원할 같은 색이 존재하는지확인
//                 if (source == candi[a][j + 1])
//                 {
//                     jump = true;
//                     suin++;
//                 }
//             }
//             if (j - 1 != -1 && !jump)
//             {
//                 if (source == candi[a][j - 1])
//                 {
//                     jump = true;
//                     suin++;
//                 }
//             }
//             if (!jump) // 구원실패
//                 break;
//         }
//         else
//             break;
//     }
//     result = suin > result ? suin : result;
//     // cout << i << " " << j << " " << result << endl;
//     return result;
// }

int main()
{

    int result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    { // 입력받기
        for (int j = 0; j < N; j++)
            cin >> candi[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result = check(i, j) > result ? check(i, j) : result;
        }
    }
    cout << result;
    return 0;
}
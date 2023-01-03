// #include <iostream>

// using namespace std;

// int main()
// {
//     cin.tie(0);
//     cout.tie(0);

//     int N;
//     cin >> N;
//     int height[N];

//     for (int i = 0; i < N; i++)
//     {
//         cin >> height[i];
//         bool check = false;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (height[i] < height[j])
//             {                         // 앞사람이 크면
//                 cout << j + 1 << " "; // 앞사람번호
//                 check = true;         // 체크(큰사람 존재함.
//                 break;
//             }
//         }
//         if (!check)
//             cout << 0 << " ";
//     }
//     return 0;
// }

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int height[N];

    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
        bool check = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (height[i] < height[j])
            {                         // 앞사람이 크면
                cout << j + 1 << " "; // 앞사람번호
                check = true;         // 체크(큰사람 존재함.
                break;
            }
        }
        if (!check)
            cout << 0 << " ";
    }
    return 0;
}
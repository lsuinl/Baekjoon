
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int check[8001] = {
    0,
};

bool compare(int a, int b)
{
    a = a < 0 ? abs(a) + 4000 : a;
    b = b < 0 ? abs(b) + 4000 : b;
    return check[a] > check[b];
}

int main()
{
    int n;
    cin >> n;

    int suin[n];
    double san = 0;
    int bin;
    int min = 4001, max = -4001;
    for (int i = 0; i < n; i++)
    {
        cin >> suin[i];

        san += suin[i];

        max = max > suin[i] ? max : suin[i];
        min = min > suin[i] ? suin[i] : min;

        if (suin[i] < 0)
            check[abs(suin[i]) + 4000]++;
        else
            check[suin[i]]++;
    }

    // 산술평균
    san = floor(san / n + 0.5) == -0 ? 0 : floor(san / n + 0.5);
    //중앙값
    sort(suin, suin + n);
    int middle = suin[n / 2];
    //최빈값
    sort(suin, suin + n, compare);

    int a = suin[0] < 0 ? abs(suin[0]) + 4000 : suin[0]; //최빈값 1순위+최고낮은값
    int b = a;
    for (int i = 1; i < n; i++)
    {
        if (suin[0] != suin[i])
        {
            b = suin[i] < 0 ? abs(suin[i]) + 4000 : suin[i]; //최빈값 2순위&&a와 다른 값
            break;
        }
    } 
    if(check[a]==check[b])
        bin=b>4000?(b-4000)*-1:b;
    else
        bin=a>4000?(a-4000)*-1:a;


    // 범위
    int bound = max - min;
    cout << san << "\n"
        << middle << "\n"
        << bin << "\n"
        << bound;
    return 0;
}




//왜요왜요ㅐ왜요왜요왜요
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
    for (int i = 0; i < n; i++)
    {
        cin >> suin[i];

        san += suin[i];
        if (suin[i] < 0)
            check[abs(suin[i]) + 4000]++;
        else
            check[suin[i]]++;
    }

    // 산술평균
    san = (int)round(san / (double)n) == -0 ? 0 : (int)round(san / (double)n);
    //중앙값
    sort(suin, suin + n);
    int middle = suin[(n-1) / 2];
    //범위
    int bound = suin[n-1]-suin[0];

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
    cout << san << "\n"
        << middle << "\n"
        << bin << "\n"
        << bound;
    return 0;
}

// #include<iostream>
// #include<algorithm>
// #include<cmath>
// #include<vector>
// using namespace std;

// int coordinate[500001];
// int cnt[8001];
// int N, a, b, c, d;
// int sum = 0;

// int main()
// {
// 	cin >> N;

// 	for (int i = 0; i < N; i++)
// 	{
// 		cin >> coordinate[i];
// 		sum += coordinate[i];
// 		cnt[coordinate[i]+4000]++;
// 	}
	
// 	sort(coordinate, coordinate + N);
	
// 	int flag;
// 	int max = 0;
	
// 	for (int i = 0; i < 8001; i++)
// 	{
// 		if (cnt[i] > max)
// 		{
// 			max = cnt[i];
// 			flag = i;
// 		}
// 	}

// 	for (int i = flag + 1; i < 8001; i++)
// 	{
// 		if (cnt[i] == max)
// 		{
// 			flag = i;
// 			break;
// 		}
// 	}

// 	a = round(double(sum) / N);
// 	b = coordinate[(N - 1) / 2];
// 	c = flag - 4000;
// 	d = coordinate[N - 1] - coordinate[0];

// 	cout << a << "\n";
// 	cout << b << "\n";
// 	cout << c << "\n";
// 	cout << d << "\n";
// }
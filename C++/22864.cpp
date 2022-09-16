#include <iostream>

using namespace std;

int main()
{
    int a, b, c, m, day = 24, p = 0, result = 0;
    cin >> a >> b >> c >> m;

    while (day != 0) //24시간 쓸 때까지 반복
    {
        if (p+a>m) //한시간 더 할 경우의 피로도가m을 넘기면..
        {
            p = p-c>0? p-c:0; 
            day--;
            continue;
        }
        else
        {
            day--;
            result += b;
            p += a;
        }
    }
    cout << result;
    return 0;
}

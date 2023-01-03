#include <iostream>

using namespace std;

int main()
{
    int N, result = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    cin >> N;
    N=1000-N;
    for (int e : coin)
    {
        result += N / e;
        N = N % e;
    }
    cout<<result;
    return 0;
}
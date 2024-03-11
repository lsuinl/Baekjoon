#include <iostream>

using namespace std;

int suin(int k, int n)
{
    if (n == 1) //1호의 경우 모두 1명
        return 1;
    if (k == 0) //0층의 경우 b호는 b명
        return n;
    //재귀호출. k층n호 사람의 수=k-1층 n호 사람+k층 n-1호사람
    //k층 n-1호 사람=k-1층의 1~n-1호의 합.
    //k-1층 n호 사람=k-1층의 n호.
    return (suin(k - 1, n) + suin(k, n - 1)); 
}

int main()
{
    int t, k, n; //입력받는 수
    cin >> t; //테스트 게이스
    for (int i = 0; i < t; i++)
    {
        cin >> k >> n;  //k층, n호
        cout << suin(k, n) << endl; //결과 출력
    }
}

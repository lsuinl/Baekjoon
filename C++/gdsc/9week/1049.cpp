#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, result = 0;
    int minbundle = 6006, minsingle = 1001;

    cin >> n >> m;
    int bundle[m], single[m];
    for (int i = 0; i < m; i++)
    {
        cin >> bundle[i] >> single[i];
        bundle[i] = min(bundle[i], single[i] * 6); //번들과 6개 낱개 중 저렴한 값 선택
        minbundle = bundle[i] < minbundle ? bundle[i] : minbundle; //번들의 최솟값 저장
        minsingle = single[i] > minsingle ? minsingle : single[i]; //낱개의 최솟값 저장
    }
    result += (n / 6) * minbundle; //6개 번들로 살 수 있는 개수만큼 더하기
    n = n % 6; //6개미만
    result += (n * minsingle > minbundle ? minbundle : minsingle * n);
    cout << result;
    return 0;
}
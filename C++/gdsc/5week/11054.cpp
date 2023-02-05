#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[1001], N;

int DP()
{
    int dpleft[1001] = {0,};
    for (int i = 0; i < N; ++i) 
    {
        int a = arr[i];
        for (int j = 0; j < i; ++j) //0번부터 i이전까지의 값(왼쪽) 검사
            if (a > arr[j])
                dpleft[i] = max(dpleft[i], dpleft[j] + 1);
    }

    int dpright[1001] = {0,};
    for (int i = N - 1; i >= 0; --i)
    {
        int a = arr[i];
        for (int j = N - 1; j > i; --j) //N-1번부터 i+1번까지 검사(끝에서부터 증가하므로 끝번부터 갱신)
            if (a > arr[j])
                dpright[i] = max(dpright[i], dpright[j] + 1);
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, (dpright[i] + dpleft[i])); //왼쪽과 오른쪽 검사한 값의 합을 비교하여 저장s
    return result + 1; //자기자신을 포함한 값 출력
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i]; //입력받기
    cout << DP();

    return 0;
}
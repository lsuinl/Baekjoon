#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
// https://jaimemin.tistory.com/1454
// DFS

int N;
string s;
int result = INT_MIN; // int형이 표현할 수 있는 최솟값

// 계산합니다.
int caculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

void check(int idx, int value)
{ // 인덱스와 값.
    if (idx >= N)
    {                                // 인덱스가 문자열의 길이와 같거나 크면
        result = max(result, value); // result에 저장된 값과 value값을 비교하여 최댓값 저장
        return;                      // 끝.
    }

    char op = idx >= 1 ? s[idx - 1] : '+';        // idx가 1보다 크거나 같으면 s[idx-1]에 저장된 문자를 저장, 아니면 +를 저장=>0+0=0이니까.
    int temp = caculate(value, s[idx] - '0', op); // 계산하기. 값/s[idx]에서 0을뺸 아스키코드값.(왜냐면 문자열이니까) / op에 저장된 수식.

    check(idx + 2, temp); // 재귀호출. idx+2번째 값과 계산한 수식의 결과를 보냄
    if (idx < N - 2)
    {                                                                // 인덱스의 값이 문자열의 문자열의 길이-2의 값보다 작으면
        temp = caculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]); // 계산하기.
        temp = caculate(value, temp, op);                            // 계산하기
        check(idx + 4, temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // 수행시간을 줄여주는 코드(1)
    cin.tie(0);                   // 수행시간을 줄요주는 코드(2)
    cin >> N;
    cin >> s;
    check(0, 0);
    cout << result << "\n"; // 결과를 출력함
    return 0;
}
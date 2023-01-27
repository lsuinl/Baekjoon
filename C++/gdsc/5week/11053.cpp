#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//https://bitwise.tistory.com/215
using namespace std;

// int DP(){
//     if(N==1) return 1; //주어진 값이 1개면 1

//     int Max=1;

//     for(int i=0;i<N-1;i++){ //기준숫자
//         int result=1;
//         a=A[i]; //기준숫자 지정
//         for(int j=i+1;j<N;j++){ //기준숫자에서 가장 큰 수열 찾기
//             if(a<A[j]){ //기준숫자보다 크면(증가수열)
//                 a=A[j]; //기준숫자에 큰 숫자를 저장
//                 result++;//수열의 길이 증가
//             }
//         }
//         Max=max(result,Max); //기준 숫자를 바꿀 때마다 큰 숫자 출력
//     }
// }

int N, a;
vector<int> A;

int DP()
{
    if(N==1){
        return 1;
    }
        int dp[1001];
    std::fill_n(dp, 1001, 1);

    int sol = 1;//결과
    for (int i = 0; i < N; ++i)
    {
        int code = A[i]; //1번부터 N번까지 검사합니다
        for (int j = 0; j < i; ++j) //1번부터 i번이전까지 점사합니다
        {
            if (code > A[j]) //민액 기준값이 i이전값보다 크다면
            {
                dp[i] = max(dp[i], dp[j] + 1); //i이전값의 값에 1을 더한 값(그리고 그런느낌으로 저장해둔 값)을 비교하여 가장큰거고르기
            }
        }
        sol = max(sol, dp[i]); //제일큰거
    }
    return sol;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    cout << DP();

    return 0;
}
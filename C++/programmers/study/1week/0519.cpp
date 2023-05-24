//LV 1. 자릿수 더하기
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string number=to_string(n);
    for(int i=0;i<number.length();i++){
        answer+=number[i]-48;
    }
    return answer;
}
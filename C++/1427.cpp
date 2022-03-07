#include <iostream>
//(유클리드 호제법) https://fjvbn2003.tistory.com/37
using namespace std;
/*유클리드 호제법 : 큰수를 작은수로 나눈다->나누는 수를 나머지로 계속 나눈다
  나머지가 0이 나올때까지 반복한다. ->나머지가 0일 때 나누는 수가 최대공약수
  + 최대공약수*최소공배수=두 수의 곱. 따라서 최소공배수= 두 수의 곱/최대공약수*/


int suin(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << suin(a, b) << endl << (a * b) / suin(a, b);
    return 0;
}
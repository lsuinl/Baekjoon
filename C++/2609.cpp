#include <iostream>
#include <string> //to_string()함수
#include <algorithm> //sort 함수 

//sort 함수 사용해보기
using namespace std;
/*
int main() {
    char n[11];
    cin >> n;
    for (int j = 0; j < strlen(n); j++) {
        for (int i = 0; i < strlen(n); i++) {
            int z;
            if (n[j] > n[i]) {
                z = n[i];
                n[i] = n[j];
                n[j] = z;
            }
        }
    }

    cout << n;

    return 0;
}*/

bool compare(char a, char b) {
    return a > b;
}

int main() {
    string a;
    int n;
    cin >> n;

    //n을 string형으로 변환해서 a에 저장
    a = to_string(n);

    //a의 시작부터 끝까지 (compare로 참거짓판별) 비교해서 정렬
    //https://cocoon1787.tistory.com/189
    //참이면 왼쪽으로, (참=더 큰 수)?????맞나
    sort(a.begin(), a.end(), compare);

    cout << a;
}
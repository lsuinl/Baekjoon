#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
 
using namespace std;
int num;
int strike;
int ball;
bool arr[1000];
 
int main() {
 
    memset(arr, true, sizeof(arr)); //true 는 정답이 될 가능성이 있음을 의미
    int n;
    cin >> n;
 
    for (int i = 123; i <= 999; i++) {
        string tmp = to_string(i);  //문자열로 바꿔서 문자별로 서치가 가능하게 만듬
 
        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) //서로 다른숫자만 가능하기때문, 같으면 가능성x
            arr[i] = false;
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) //0도 사용안함
            arr[i] = false;
    }
 
    while (n--) {        
 
        cin >> num >> strike >> ball;
        for (int i = 123; i <= 999; i++) {
            int stcnt = 0; 
            int blcnt = 0;
            if (arr[i] == true) { //만약 i가 가능성이 있다면
 
                string a = to_string(num); //받은숫자
                string b = to_string(i); //비교대상
 
                for (int q = 0; q < 3; q++)
                    for (int w = 0; w < 3; w++) {
 
                        if (q == w && a[q] == b[w]) //자릿수도 같고 숫자도 같으면
                            stcnt++; //스트라이크!
 
                        if (q != w && a[q] == b[w]) //자릿수는다른데 같으면
                            blcnt++; //볼!
                    }
                if (stcnt != strike || blcnt != ball) //입력받은 스트라이크, 볼 갯수가 다르면 이건 맞지 않는 숫자
                    arr[i] = false; //i는 false 로 만들어서 더이상 탐색 x
            }
        }
    }
    int cnt = 0; //정답 샐 변수
    for (int i = 123; i <= 999; i++) {
        if (arr[i] == true)
            cnt++;
    }
    cout << cnt;
 
    return 0;
}

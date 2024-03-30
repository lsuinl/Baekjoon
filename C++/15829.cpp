// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// string pluss(string a, string b){ // 덧셈
//     string result;
//     int carry = 0;
//     for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
//         int sum = carry;
//         if (i >= 0) sum += a[i] - '0';
//         if (j >= 0) sum += b[j] - '0';
//         result += sum % 10 + '0';
//         carry = sum / 10;
//     }

//     reverse(result.begin(), result.end());
//     return result;
// }

// string mix(string a, string b){ //곱셈: b를 a번더하기.
//     string sum="0";
//     for(int i=0;i< stoi(a);i++)
//         sum=pluss(sum,b);
//     return sum;
// }

// int main(){
//     int n;
//     string result="0", word;
//     cin>>n;
//     cin>>word;
//     for(int i=0;i<n;i++){
//         string mid=mix("31",to_string(i)); //31을 i번
//         mid=mix(to_string(word[i]-'a'+1),mid); //곱한 값에 알파벳길이?만큼의 곱을 더
//         result=pluss(result,mid); //이전 합과 더하기
//     }
//     string mod = "1234567891";
//     while(result.size()>10){
//         for(int i=0;i<10;i++){ //수정된 부분
//             if( result[result.size()-1-i]-(mod[9-i]-'0')<0){
//                 result[result.size()-2-i]--;
//                 result[result.size()-1-i]=10+(result[result.size()-1-i]-(mod[9-i]-'0'));
//             }
//             else 
//                 result[result.size()-1-i]-=(mod[9-i]-'0');
//         }
//     }
//     if(stoll(result)>stoll(mod))
//         cout<<stoll(result)%stoll(mod);
//     else cout<<stoll(result);
//     return 0;
// }

//아;
#include <iostream>
#include <string>
#define r 31
#define M 1234567891

using namespace std;

int main () {
    int l, i;
    long long hash = 0, R = 1;
    string str;

    cin >> l >> str;

    for (i = 0; i < str.length(); i++) {
        hash += ((str[i] - 'a' + 1) * R) % M; 
        hash %= M;
        R = (R * r) % M;
    }
    cout << hash;
}
//https://codejin.tistory.com/68
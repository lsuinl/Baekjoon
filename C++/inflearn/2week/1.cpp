#include <iostream>
#include <string.h>
//문자열에서 숫자 찾아 더하기
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string suin;
    cin>>suin;
    int result=0;
    for(int i=suin.size()-1;i>=0;i--){
        int digit=1;
        while(suin[i]<58&&suin[i]>47 ){
            result+=(suin[i]-48)*digit;
            digit*=10;
            i--;
        }
    }
    cout<<result;

    return 0;
}
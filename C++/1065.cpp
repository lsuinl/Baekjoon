#include <iostream>
using namespace std;
//니가몬데 니가몬데!!!!!!!!!!!!!!왜틀렸대!!!!!!!!!!
int suin(int n){
    int result;
    if(n<100){
        result=n;
    }
    else{
        result=99;
        for(int i=100;i<=n;i++){
            if((i/100)-(i/10)%10 == (i/10)%10-i%10){
                result++;
            }
        }
    }

    return result;
}

int main(void){
    int n, result;
    cin>>n;
    result=suin(n);
    cout<<result;
    return 0;
}
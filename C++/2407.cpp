#include <iostream>
#include <string.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int j=1;
    int n,m;
    __uint128_t result=1, nq=1;
    cin>>n>>m;
    for(int i=(n-m)+1;i<=n;i++){
        result*=i;
        if(result%j==0){
            result/=j;
        }
        else{
            nq*=j;
        }
        if(nq!=1 &&result%nq==0){
            result/=nq;
            nq=1;
        }
        j++;
    }
    result/=nq;
    string s;
    if(result == 0)
        cout << 0;
    while(result>0){
        int num = result%10;
        s.insert(s.begin(),'0'+num);
        result/=10;
    }
    cout<<s;
    return 0;
}
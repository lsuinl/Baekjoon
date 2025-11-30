#include <iostream>

#define mod  1000000007

using namespace std;
long long mod_pow(long long a, long long b){
    long long res=1;
    while(b){
        if(b&1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    int m;
    long long sum=0;
    cin>>m;
    for(int i=0;i<m;i++){
        long long n,s,result;
        cin>>n>>s;
        result = s * mod_pow(n,mod-2)%mod;
        sum = (sum+result)%mod;
    }
    cout<<sum;
    return 0;
}
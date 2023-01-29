#include <iostream>

using namespace std;

int main(){
    long long dp[91],n;
    dp[0]=0;
    dp[1]=1;

    cin>>n;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}
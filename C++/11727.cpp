//2*n 타일링 2
#include <iostream>

using namespace std;

int main(){
    int dp[1001],n;
    dp[1]=1;
    dp[2]=3;
    dp[3]=5;
    cin>>n;
    for(int i=4;i<=n;i++){
        dp[i]=(dp[i-1]+2*dp[i-2])%10007;
    }
    cout<<dp[n];
    return 0;
}

//점화식: dp[n]=dp[n-1]+2*dp[n-2]
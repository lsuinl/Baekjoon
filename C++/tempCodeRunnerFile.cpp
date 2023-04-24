#include <iostream>

using namespace std;

int main(){
    int n,m;
    long long dp[1001][1001];
    dp[1][2]=1;
    dp[1][1]=1;
    dp[2][1]=1;
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i==2) dp[i-1][j]=1;
            if(j==2) dp[i][j-1]=1;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%1000000007;
        }
    }
    cout<<dp[n][m];
    return 0;
}

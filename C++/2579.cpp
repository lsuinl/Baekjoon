#include <iostream>
#include <map>
using namespace std;
//도착지점부터 생각해봅니다.
//dp[i] = dp[i-2]+star[i]
//dp[i] = dp[i-1]+dp[i-3]+star[i]
// void dp(int n,bool con){
//     if(n>=m)
//         return;
//     root[n+1]=root[n]+star[n+1]<root[n+1]?root[n+1]:root[n]+star[n+1];
//     root[n+2]=root[n]+star[n+2]<root[n+2]?root[n+2]:root[n]+star[n+2];
//     dp(n+2,false);
//     if(!con)
//         dp(n+1,true);
// }
// int main(){
//     cin>>m;
//     star.push_back(0);
//     root[m]=0;
//     for(int i=0;i<m;i++)
//     {
//         int a;
//         cin>>a;
//         star.push_back(a);
//         root[i]=0;
//     }
//     dp(0,false);
//     cout<<root[m];
//     return 0;
// }

int main(){
    int m;
    int star[301], dp[301];
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>star[i];
        
    if(m>=3){
        dp[1]=star[1];
        dp[2]=star[1]+star[2];
        dp[3]=max(star[1]+star[3],star[2]+star[3]);
        for(int i=4;i<=m;i++)
        {
            dp[i]=max(dp[i-2]+star[i],dp[i-3]+star[i-1]+star[i]);
        }
    }
    else{
        for(int i=1;i<=m;i++){
            dp[m]+=star[i];
        }
    }
    cout<<dp[m];
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t[16], p[16], dp[16],n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<i;j++){
            if(j+t[j]<=i){
                dp[i]=max(dp[i],dp[j]+p[j]);
            }
        }
    }
    cout<<dp[n+1];
    return 0;
}
// 첫 번째 for: i번째 ~ 퇴사하는 날까지 최대 수익
//두 번째 for: i번째 이전에 가능한 모든 상담에 대해서 최대 수익 중에서 가장 큰 값 dp[i]에 저장
#include <iostream>

using namespace std;
//https://m.blog.naver.com/occidere/220786307316
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int sticker[2][100001];
        int sum[2][100001];
        int n;
        cin>>n;
        for(int j=0;j<2;j++){
            for(int z=1;z<=n;z++){
                cin>>sticker[j][z];
            }
        }
        //초기값
        sum[0][0]=sum[1][0]=0;
        sum[0][1]=sticker[0][1];
        sum[1][1]=sticker[1][1];
        for(int j=2;j<=n;j++){
            sum[0][j]= max(sum[1][j-1],sum[1][j-2])+sticker[0][j];
            sum[1][j]= max(sum[0][j-1],sum[0][j-2])+sticker[1][j];
        }
        //값 도출
        cout<<max(sum[0][n],sum[1][n])<<"\n";
    }
    return 0;
}

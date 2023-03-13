#include <iostream>
#include <vector>

using namespace std;

int suin[32][32]={0,};
int n,k,result;

//(n,k)=(n-1,k-1)+(n-1,k)

void DP(int i,int j){
    if(i==n && j==k){
        result=suin[n-1][k-1]+suin[n-1][k];
        return;
    }
    else if(j==i || j==1){ //양끝은 0입니다.
        suin[i][j]=1;
        if(j!=i) DP(i,j+1);//처음이었다면 다음칸으로..
        else DP(i+1,1); //맨끝이었다면 다음줄로..
    }
    else{
        suin[i][j]=suin[i-1][j-1]+suin[i-1][j];
        DP(i,j+1);
    }
}

int main(){
    cin>>n>>k;
    if(n==1 || n==2){
        cout<<1;
    }
    else{
        DP(1,1);
        cout<<result;
    }
    return 0;
}


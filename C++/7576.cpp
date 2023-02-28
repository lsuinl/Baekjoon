#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
//1:익은 토마토,-1:토마토가없는상자,0:안익은토마토
int main(){
    int m,n;
    cin>>m>>n;
    int box[n][m], result[n][m];
    int check=m*n;
    fill_n(&result[0][0],n*m,0); //초기화
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                q.push({i,j});
                result[i][j]=1;
                check--;
            }
            else if(box[i][j]==-1){
                result[i][j]=-1;
                check--;
            }
        }
    }
    //처음부터 모두 익은 상태: 0, 모두 익을 수 없음:-1, 나머지: 모두 익는 데 걸리는 날짜
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        int day=result[q.front().first][q.front().second];//날짜
        q.pop();
        for(int i=0;i<4;i++){
            if((x+dx[i]<n &&x+dx[i]>=0)&&(y+dy[i]<m &&y+dy[i]>=0)){ //범위체크
                if(result[x+dx[i]][y+dy[i]]==-1){//못채우는거면
                    continue;
                }
                else{
                    if(result[x+dx[i]][y+dy[i]]==0||result[x+dx[i]][y+dy[i]]>day+1){
                    result[x+dx[i]][y+dy[i]]=day+1;
                    q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
    }
    int maxresult=0;
    for(int i=0;i<n;i++){
        if(check==0){ //이미 익었을 때,
            cout<<0;
            break;
        }
        else if(check==-1)  break;

        for(int j=0;j<m;j++){
            if(result[i][j]==0){ //모두 익을 수 없음
                cout<<-1;
                check=-1;
                break;
            }
            maxresult=max(maxresult,result[i][j]);
            if(i==n-1&&j==m-1){
                cout<<maxresult-1;
            }
        }
    }
    return 0;
}
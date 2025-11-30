#include <iostream>
#include <queue>
#include <cstring> 

using namespace std;

int map[101][101];
int n,m,result=0;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
    
bool visited[101][101];

//상태업데이트
void outdoor(){
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=true;
    while(!q.empty()){
        cout<<"gd";
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(x>=0&&x<=n&&y>=0&&y<=m){
                if(map[xx][yy]==0&&visited[xx][yy]==false){
                    visited[xx][yy]=true;
                    q.push({xx,yy});
                }
            }
        }
    }
    
}
//개별녹이기
bool melt(int x,int y){
    int count=0;
    for(int i=0;i<4;i++){
        if(visited[x+dx[i]][y+dy[i]])
            count++;
    }
    if(count>1)
        return true;
    return false;
}

//entire
int entire(){
    int count=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(map[i][j]==1 && melt(i,j)){
                map[i][j]=0;
                count++;
            };
        }
    }
    return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int count=0;
    //입력
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1) count++;
        }
    }
    int sum=0;
    while(count!=sum){
        //r공간확보
        outdoor();
        //녹여뿐다.
        sum+=entire();  
        cout<<sum;
        result++;
    }
    cout<<result;
    return 0;
}
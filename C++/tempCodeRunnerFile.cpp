#include <iostream>
#include <queue>

using namespace std;
char color[100][100];//RGB
bool normalvisited[100][100]={false,};
bool colorsvisited[100][100]={false,};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n;

void BFS(int i, int j, int checked){ //checked: 색약여부
    queue<pair<int,int>> q;
    char selectcolor=color[i][j];
    q.push({i,j});
    if(checked==false){ //정상
        while(!q.empty()){
        for(int i=0;i<4;i++){
        int x=q.front().first+dx[i];
        int y=q.front().second+dy[i];
            if((x>=0&&x<n)&&(y>=0&&y<n)){
                    if(color[x][y]==selectcolor && normalvisited[x][y]==false){
                        normalvisited[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
                q.pop();
        }    
    }
    else{ //적록색약
        while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            x+=dx[i];
            y+=dy[i];
            if((x>=0&&x<n)&&(y>=0&&y<n)){
                    if(color[x][y]==selectcolor && colorsvisited[x][y]==false){
                        colorsvisited[x][y]=true;
                        q.push({x,y});
                    }
                    else if((color[x][y]=='R'||color[x][y]=='G')&&(selectcolor=='R'||selectcolor=='G') && colorsvisited[x][y]==false){
                        colorsvisited[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
    }
}
}

int main(){
    int normal=0, colors=0;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>color[i][j];
        }
    }
    
    //정상인
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!normalvisited[i][j]) { //정상
                normalvisited[i][j]=true;
                normal++;
               // cout<<i<<j<<endl;
                BFS(i,j,false);
            }
            if(!colorsvisited[i][j]){ 
                colorsvisited[i][j]=true;
                colors++;
                BFS(i,j,true);
            }
        }
    }
    cout<<normal<<" "<<colors;

    return 0;
}
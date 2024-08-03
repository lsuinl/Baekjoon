#include <iostream>
#include <queue>

using namespace std;
int maps[1001][1001]={0,};
bool visited[1001][1001]={false,};

void BFS(int x, int y){
    queue<pair<int,int>> q;
    
    visited[x][y]=true;
    maps[x][y]=0;
    q.push({x,y});
    int  num=1;
    vector<pair<int,int> > v;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        pair<int,int> forward[4]={{dx+1,dy},{dx-1,dy},{dx,dy+1},{dx,dy-1}};
        for(int i=0;i<4;i++){
            if(forward[i].first>-1 && forward[i].second>-1){ //범위를 벗어나지 않도록.
                if(maps[forward[i].first][forward[i].second]!=0 
                && visited[forward[i].first][forward[i].second]==false){
                    visited[forward[i].first][forward[i].second]=true;
                    maps[forward[i].first][forward[i].second]=num;
                    v.push_back(forward[i]);
                }
            }
        }
        if(q.empty()){
            for(int i=0;i<v.size();i++){
                q.push(v[i]);
            }
            num++;
            v.clear();
        }
    }
}

//0:못감 , 1:갈수있음 , 2:목표지점
int main(){
    int n, m;
    int x,y;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maps[i][j];
            if(maps[i][j]==2) {x=i;y=j;}
        }
    }
    BFS(x,y);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false && maps[i][j]==1){
                maps[i][j]=-1;
            }
            cout<<maps[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
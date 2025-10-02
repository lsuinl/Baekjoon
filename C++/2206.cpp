#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct node{
    int x;
    int y;
    int cost;
};

int map[1001][1001];
int datas[1001][1001];

void bfs(){
    queue<node> q;
    q.push({1,1});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        if(y+1<1001 &&datas[x][y+1]>=cost+1)
            q.push({x,y+1,cost+1});
        if(y-1>0&&datas[x][y-1]>=cost+1)
            q.push({x,y-1,cost+1});
        if(x+1<1001&&datas[x+1][y]>=cost+1)
            q.push({x+1,y,cost+1});
        if(x-1>0&&datas[x-1][y]>=cost+1)
            q.push({x-1,y,cost+1});   
    }
}

int main(){
    vector<pair<int,int>> xy;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            if(map[i][j]) xy.push_back({i,j});
        }
    }
    fill(&datas[0][0], &datas[0][0] + 1001 * 1001, INT_MAX);
    datas[1][1]=1;
    for(int i=0;i<xy.size();i++){
        map[xy[i].first][xy[i].second]=0;
        bfs();
        map[xy[i].first][xy[i].second]=1;
    }

    cout<<map[n][m];
    return 0;
}
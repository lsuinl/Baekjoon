#include <iostream>
#include <queue>

using namespace std;

int n,m;
int miro[101][101]={0,};
int visited[101][101]={0,};

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=1;
    pair<int,int> check[4]={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int num = visited[front.first][front.second]+1;
        for(int i=0;i<4;i++)
        {
            pair<int,int> cur = {front.first+check[i].first,front.second+check[i].second};
            if(cur.first>-1 &&cur.second>-1){
                if(miro[cur.first][cur.second]==1 && visited[cur.first][cur.second]==0)
                {
                    visited[cur.first][cur.second] = num;
                    q.push(cur);
                }
            }
        }
    }
}

//1;가능, 0:불가능, 왼쪽위부터 오른쪽밑까지..
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string line;
        cin>>line;
        for(int j=0;j<m;j++){
            miro[i][j] = line[j]-48;
        }
    }
    bfs();
    cout<<visited[n-1][m-1];
    return 0;
}
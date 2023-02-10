#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
//https://hgu-can.tistory.com/entry/C-find-vs-findif-%EC%B0%A8%EC%9D%B4%EC%A0%90
using namespace std;

int n, m, k;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
vector<pair<int,int>> suin;

int DFS(pair<int,int> xy){
    int result=0;
    queue<pair<int,int>> q;
    int x=xy.first;
    int y=xy.second;
    q.push({x,y});
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            vector<pair<int,int>>::iterator it = find(suin.begin(),suin.end(),{x+dx[i],y+dy[i]});
            if(it==suin.end()){
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }

    return result;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        suin.push_back({x,y});
    }
    int result=0;

    while(!suin.empty()){
        result= result>DFS(suin.front())? result:DFS(suin.front());
    }
    cout<<result;
    return 0;
}
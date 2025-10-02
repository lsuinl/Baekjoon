#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <limits.h>
using namespace std;

vector<vector<pair<int,int>>> root;
int items[101];
int n,m,r;

int bfs(int start){
    int visited[101];
    fill(visited,visited+n+1,INT_MAX);
    visited[start]=0;
    int sum=items[start]; //아이템 합
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<root[front].size();i++){
            int end=root[front][i].first; //도착지
            int cost=root[front][i].second+visited[front];//이동비용
            if(cost>m) continue; //최대 비용 초과
            if(visited[end]>cost){ //싸게 갈 수 있음
                if(visited[end]==INT_MAX) {
                    sum+=items[end];
                }
                visited[end]=cost;
                q.push(end);
            }
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>r;

    root.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>items[i];
    }

    for(int i=0;i<r;i++){
        int a,b,cost;
        cin>>a>>b>>cost;
        root[a].push_back({b,cost});
        root[b].push_back({a,cost});
    }

    int result=0;
    for(int i=1;i<=n;i++){
        int emp=bfs(i);
        result= emp>result?emp:result;
    }
    cout<<result;
    return 0;
}
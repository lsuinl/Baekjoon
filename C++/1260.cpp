#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1001

int n,m,v;
bool visited[MAX];
vector<int> suin[MAX];
queue<int> q;

void visitreset(){
    for(int i=0;i<=n;i++){visited[i]=false;}
}


void dfs(int v){
    if(visited[v]){return;}
    visited[v]=true;
    cout<<v<<" ";
    for(int i=0;i<suin[v].size();i++){
        int x=suin[v][i];
        if(!visited[x]){
            dfs(x);
        }
    }
}

void bfs(){ 
    q.push(v);
    visited[v]=true;
    while(!q.empty()){
        int x= q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0; i< suin[x].size(); i++){
            int y = suin[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true; 
            }
        }
        
    }
}

int main(){
    cin>>n>>m>>v;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        suin[a].push_back(b);
        suin[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(suin[i].begin(),suin[i].end());
    }

    visitreset();
    dfs(v);
    cout<<'\n';
    visitreset();
    bfs();

    return 0;
}
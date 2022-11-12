#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int computer, n,result=0;
    cin>>computer>>n;
    vector<int> birus[computer+1];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        birus[a].push_back(b);
        birus[b].push_back(a);
    }

    bool visit[computer+1];
    for(int i=1;i<=computer;i++)
        visit[i]=false;
    queue<int> q;
    q.push(1);
    visit[1]=true;
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int i=0;i<birus[x].size();i++){
            int y=birus[x][i]; //x번 노드에 연결된 컴퓨터를 개별로 검사
            if(!visit[y]){
                q.push(y); //연결 q에 추가해서 또 검사해야댐
                visit[y] = true; //방문표시
                result++; //결과추가
            }
        }
    }
    cout<<result;

    return 0;
}
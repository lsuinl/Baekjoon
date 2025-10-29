#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

using namespace std;

vector<vector<pair<int,int>>> road;

int nodes[801];
int n,e;

int move(int start, int end){
    fill(nodes, nodes + n+1, INT_MAX);
    nodes[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(nodes[front]>nodes[end])
            continue;

        for(int i=0;i<road[front].size();i++){ //현재지점에서 뻗는 길들
            int goal = road[front][i].first; //도착점
            int cost =road[front][i].second+ nodes[front]; //총이동비용

            //온적없거나, 지금의 경로가 더 저렴한경우
            if(nodes[goal]> cost){
                nodes[goal] =cost;//갱신
                q.push(goal);
            }  
        }
    }
    return nodes[end];
}

int main(){
    cin>>n>>e;
    road.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        //a-b c:비용
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }
    int v1,v2;
    cin>>v1>>v2; 
    
    //1->v1->v2->e
    long long one = move(1,v1);
    long long two = move(v1,v2);
    long long three = move(v2,n);
    long long result=one+two+three;
        cout<<one<<" "<<two<<" "<<three<<endl;
    
    //1->v2->v1->e
    one = move(1,v2);
    two = move(v2,v1);
    three = move(v1,n);
        cout<<one<<" "<<two<<" "<<three<<endl;
    
    result=min((long long)(one+two+three),result);
    if(result>=INT_MAX)
        cout<<-1;
    else
        cout<<result;
    return 0;
}
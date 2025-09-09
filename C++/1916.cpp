#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>
using namespace std;

int n,m, start,goal;
vector<vector<pair<int,int>>> bus(1001); //출발 /목적-비용
map<int, int> cost;

void citie(int start){
    vector<bool> inQueue(n + 1, false);
    queue<int> q;
    inQueue[start] = true;
    q.push(start);
    cost[start]=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inQueue[cur] = false; 
        for(int i=0;i<bus[cur].size();i++){
            pair<int,int>  pos = bus[cur][i];
            int nextPos=bus[cur][i].first;
            int nextCost=bus[cur][i].second;
            if(cost[nextPos]>cost[cur]+nextCost){
                cost[nextPos]=cost[cur]+nextCost;
                if(!inQueue[nextPos]){
                    q.push(nextPos);
                    inQueue[nextPos]=true;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int st,en,fee;
        cin>>st>>en>>fee;
        bus[st].push_back({en,fee});
    }

    cin>>start>>goal;
    for (int i = 1; i <= n; i++) cost[i] = INT_MAX;
    cost[start] = 0;
    citie(start);
    cout<<cost[goal];
    return 0;
}
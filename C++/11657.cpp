#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct bus{
    int start;
    int end;
    int cost;
};

int minCost[601]={0,};
int n,m;
vector<bus> road;

bool find(){
    fill(minCost,minCost+n+1,INT_MAX);
    minCost[1]=0;
    
    for(int i=0;i<n;i++){
        for(auto& edge : road){
            if(minCost[edge.start]==INT_MAX) continue;
            if(minCost[edge.end]>long(minCost[edge.start])+edge.cost){
                minCost[edge.end]=minCost[edge.start]+edge.cost;
            }
        }
    }

    //무한루프
    for(auto& edge : road){
            if(minCost[edge.start]==INT_MAX) continue;
            if(minCost[edge.end]>long(minCost[edge.start])+edge.cost)
                return false;
        }
    return true;
}

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        road.push_back({a,b,c});
    }

    if(find()){
        for(int i=2;i<=n;i++){
            int result = minCost[i]==INT_MAX?-1:minCost[i];
            cout<<result<<"\n";
        }
    }
    else{
        cout<<-1;
    }
    
    return 0;
}
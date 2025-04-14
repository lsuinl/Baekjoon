#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<vector<pair<int,int>>> root(101);

void dijstra(int start, int min[]){
    priority_queue<pair<int,int>> q;
    min[start]=0;
    q.push({start,0});
    while(!q.empty()){
        int num = q.top().first;
        int cost = q.top().second;
        q.pop();

        if(min[num]<cost) continue;
        for(int i=0;i<root[num].size();i++){
            int next = root[num][i].first;
            int nextCost = cost +root[num][i].second;
            if(nextCost<min[next]){
                min[next]=nextCost;
                q.push({next,nextCost});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,price;
        cin>>a>>b>>price;
        root[a].push_back({b,price});
    }

    for(int i=1;i<=n;i++){
        int min[101]={};
        for(int i=1;i<=n;i++)
            min[i]=1e9;
        dijstra(i, min);
        for(int j=1;j<=n;j++){
            if(min[j]==1e9){
                cout<<0<<" ";
                continue;
            }
            cout<<min[j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}

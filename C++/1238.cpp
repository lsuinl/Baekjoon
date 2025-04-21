#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,x;//마을 수, 루트 개수 , 목적지 
vector<vector<pair<int,int>>> root(10001);

vector<int> dijstra(int start){
    vector<int> min(n+1, 1e9); 

    priority_queue<pair<int,int>> q;
    q.push({-start,0});
    min[start]=0;

    while(!q.empty()){
        int num = -q.top().first;
        int price = q.top().second;
        q.pop();
        if(min[num] < price) continue;
        for(int i=0;i<root[num].size();i++){
            int nextNum = root[num][i].first;
            int nextPrice = price + root[num][i].second;
            if(nextPrice<min[nextNum]){
                min[nextNum]=nextPrice;
                q.push({-nextNum,nextPrice});
            }
        }
    }
    return min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int a,b,t;
        cin>>a>>b>>t;
        root[a].push_back({b,t});
    }
    
    int result=0;
    vector<int> min=dijstra(x);
    for(int i=1;i<=n;i++){
        //갈때 n개=-> m으로
        int sum = dijstra(i)[x]+min[i];
        result= result> sum? result: sum;
    }
    cout<<result;

    return 0;
}
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int c,k,result=INT_MAX;
int datas[100001];
void find(){
    queue<pair<int,int>> q;
    q.push({c,0});
    while(!q.empty()){
        int node = q.front().first;
        int cost = q.front().second;
        datas[node]=cost;
        q.pop();
        if(cost<result){
            if(node>=k){
              //  cout<<"갱신: "<<node<<"카운트: " <<cost<<endl;
                result = (node-k)+cost< result ? (node-k)+cost : result;
            }
            else{
                if(node+1<100001&& datas[node+1]>cost+1)
                    q.push({node+1,cost+1});
                if(datas[node-1]>cost+1)    
                    q.push({node-1,cost+1});
                if(node*2<100001&& datas[node*2]>cost)
                    q.push({node*2,cost});


            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>c>>k;
    fill(datas, datas+100001, INT_MAX);
    find();


    cout<<result;
    return 0;
}
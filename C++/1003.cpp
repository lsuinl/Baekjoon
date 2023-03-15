#include <iostream>

using namespace std;

int one=0, zero=0;
pair<int,int> dps[41]={{0,0},};

void fibonacci(int n) {
        dps[n].second=dps[n-1].second+dps[n-2].second;
        dps[n].first=dps[n-1].first+dps[n-2].first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dps[0]={1,0};
    dps[1]={0,1};
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        one=0;
        zero=0;
        cin>>n;
        for(int j=2;j<41;j++){
            fibonacci(j);
        }
        cout<<dps[n].first<<" "<<dps[n].second<<"\n";
    }

    return 0;
}

//DP를 사용합닏.. 작은문젤르쫴서사용하는거죠? 이전에 구했떤 답을 가져와서 활용해보아요.
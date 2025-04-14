#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int n,m,result=1000000;
vector<pair<int,int>> chliken, home;

void retry(int start, vector<pair<int,int>>& comb){
    if(comb.size()==m){
        vector<int> mins(home.size(), 1e9);
        for(int i=0;i<home.size();i++){
            for(int j=0;j<comb.size();j++){
                int sum = abs(comb[j].first-home[i].first)+ abs(comb[j].second-home[i].second);
                if(mins[i]>sum ){
                    mins[i]=sum;
                }
            }
        }
        int entireSum=0;
        for(int i=0;i<home.size();i++){
            entireSum+=mins[i];
        }
        result= entireSum<result? entireSum:result;
        return;
    }

    for(int i=start;i<chliken.size();++i){
        comb.push_back(chliken[i]);
        retry(i+1,comb);
        comb.pop_back();
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            if(a==2)
                chliken.push_back({i,j});
            else if(a==1)
                home.push_back({i,j});
        }
    }
    vector<pair<int,int>> comb;
    retry(0,comb);
    cout<<result;
    return 0;
}
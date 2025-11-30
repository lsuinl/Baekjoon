#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
set<int, greater<int>>num;//내림차순 set
map<int,vector<int>> a,b;


int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        a[p].push_back(i);
        num.insert(p);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        b[p].push_back(i);
        num.insert(p);
    }
    
    vector<int> v;
    int lastA=-1,lastB=-1;
    for (auto &&i : num)
    {
        if(a[i].empty()||b[i].empty()){
            continue;
        }
        
        while(true){
            auto itA = upper_bound(a[i].begin(), a[i].end(), lastA);
            auto itB = upper_bound(b[i].begin(), b[i].end(), lastB);

            if(itA == a[i].end() || itB == b[i].end()) break; 
            lastA = *itA;
            lastB = *itB;
            v.push_back(i);
        }
    }
    
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}
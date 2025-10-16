#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x){
    cout<<"x";
    if(parent[x]==x)
        return x;
    else    
        return find(parent[x]);
}

void unions(int a, int b){
    int aP= find(a);
    int bP=find(b);
    if(aP!=bP)
        parent[a] = bP;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    parent.resize(n+1);
    for(int i=1;i<=n;i++)//초기화
        parent[i]=i;

    for(int i=0;i<m;i++){
        int cal, a,b;
        cin>>cal>>a>>b;
        if(cal==0){ //결합
            unions(a,b);
        }
        else{ //확인
            int a= find(a);
            int b=find(b);
            if(a==b)
                cout<<"YES";
            else
                cout<<"NO";
        }
    }
    return 0;
}
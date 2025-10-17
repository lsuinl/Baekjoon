#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x){
    if(x==parent[x])
        return x;
    return find(parent[x]);
}

void unions(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b)
        parent[a]=b;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int isConnect;
            cin>>isConnect;
            if(isConnect==1){
                unions(i,j);
            }
        }
    }

    bool result=true;
    int a;
    
    cin>>a;
    a=find(a);

    //여행계획
    for(int i=1;i<m;i++){
        int b;
        cin>>b;
        b=find(b);
        if(b!=a)
            result=false;   
    }

    if(result)
        cout<<"YES";
    else    
        cout<<"NO";

    return 0;
}
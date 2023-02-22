#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[9]={false,};
int result[9];
int n;

void DFS(int number){
    if(number==n){
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            result[number]=i;
            DFS(number+1);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>n;
    DFS(0);
    return 0;
}
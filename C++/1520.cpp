#include <iostream>

using namespace std;

int maps[500][500];
int result=0;
int m,n;

int dx[3]={0,-1,1};
int dy[3]={1,0,0};

void DFS(int i, int j, int num){
    for(int a=0;a<3;a++){
        int x=i+dx[a];
        int y=j+dy[a];
        if(x<n&&y<m&&x>=0){
            if(num>maps[x][y]){
                cout<<x<<y;
                cout<<maps[x][y]<<endl;
                if(x==(n-1)&&y==(m-1))
                    result++;
                else
                    DFS(x,y,maps[x][y]);
                
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maps[j][i];
        }
    }
    DFS(0,0,maps[0][0]);
    cout<<result;
    return 0;
}
#include <iostream>

using namespace std;

int check[9][9][9]={false};
int board[9][9];

void DFS(int i,int j){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                DFS(i,j);
            }
        }
    }
    
    return 0;
}
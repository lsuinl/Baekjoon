#include <iostream>

using namespace std;

char map[10000][10000];

void star(int startY, int startX){
    //cout<<startY<<" "<<startX<<endl;
    map[startY][startX]='*';
    map[startY+1][startX-1]='*';
    map[startY+1][startX+1]='*';
    for(int i=startX-2;i<=startX+2;i++){
        map[startY+2][i]='*';
    }
}

void finds(int y, int x,int len){
    if(len<=3)
        star(y,x);
    else{
        finds(y,x,len/2);
        finds(y+len/2,x-len/2,len/2);
        finds(y+len/2,x+len/2,len/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    fill(&map[0][0], &map[0][0] + 10000*10000, ' ');
    
    finds(0,n-1,n);
    //최종 출력
    for(int i=0;i<n;i++){
        for(int j=0;j<n*2-1;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
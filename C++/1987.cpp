#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

char abc[21][21];
int R, C;
int result;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

void DFS(int i, int j,int num, bool tf[26])
{
    for(int a=0;a<4;a++){
        int x = i+dx[a];
        int y = j+dy[a];
        if(x>=0 && x<R && y>=0 && y<C){
            if(tf[abc[x][y]-65]==false){
                bool newtf[26];
                copy_n(tf, 26, newtf);
                newtf[abc[x][y]-65]=true;
                result= result< num+1? num+1:result; 
                DFS(x,y,num+1,newtf);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    bool tf[26]={false,};
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>abc[i][j];
        }
    }
    tf[abc[0][0]-65]=true;
    result=1;
    DFS(0,0,1,tf);
    cout<<result;
    return 0;
}

//깊은 복사와 얕은 복사의 개념
//map<배열을 통한 작성이 가능하다면 그렇게(시간에 도움이 됨)
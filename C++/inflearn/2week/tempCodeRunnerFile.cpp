#include <iostream>
#include <algorithm>
#include <queue>
//bfs
using namespace std;

int dx[4]={-1,0,1,0}; //좌표이동(x)
int dy[4]={0,-1,0,1}; //좌표이동(y)
//board:주어진 값들 ,dis[0]:출발점으로부터의 거리값, dis[1]:도착점으로부터의 거리값
int board[1001][1001], dis[2][1001][1001]; 
queue<pair<int,int>> q; //bfs에 사용할 큐
int w,h; //주어질 가로,세로길이

void BFS(int idx){
    while(!q.empty()){ //q가 완전히 끝날때까지 진행
        int x=q.front().first; //처음좌표의 x
        int y=q.front().second; //처음좌표의 y
        q.pop(); //지금 수행하는 좌표는 지워요
        for(int i=0;i<4;i++){ //상,하,좌,우 체크
            int nx=x+dx[i]; //상하좌우에 1을 더하거나 빼서 좌표 이동
            int ny=y+dy[i];
            //이동한 좌표가 범위 안에 있으며, 아직 값이 저장되지 않았다면
            if(nx>=0 && nx<h && ny>=0 && ny<w && dis[idx][nx][ny]==0){
                if(board[nx][ny]!=1){ //움직일 수 있는 곳이 맞는지를 확인하고
					dis[idx][nx][ny]=dis[idx][x][y]+1; //1을 더하여 저장
					q.push(make_pair(nx, ny)); //이동한 좌표를 저장하여 다시 검사할것.
				}
            }
        }
    }
}


int main(){
    cin>>w>>h;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>board[i][j]; //값 입력받기

    int j;
    for(int i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(board[i][j]==2){ //2:영희의 시작 위치
                dis[0][i][j]=1;
                q.push(make_pair(i,j)); //해당 좌표쌍을 큐에 삽입.
                BFS(0);//BFS시작(0번:출발점으로부터의 거리값을 저장하는 배열에 값 저장)
                break;
            }
        }
        if(j<w) break; //j<w인 경우: 영희의 시작위치를 찾아 BFS를 완수하였음을 의미하므로 for문 종료
    }
    
     for(int i=0; i<h; i++){ //위와 같은 방법으로 도착지점으로부터의 거리도 저장
        for(j=0; j<w; j++){
            if(board[i][j] == 3){
                dis[1][i][j]=1;
                q.push(make_pair(i, j));
                BFS(1);  
                break;
            }
        }
        if(j<w) break;
    }

    int min=2147000000;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            //산딸기의 위치가 출발지점과 끝지점으로부터 도달 가능한지의 여부를 판단
            if(board[i][j]==4 && dis[0][i][j]>0 && dis[1][i][j]>0){
            	int res=dis[0][i][j]+dis[1][i][j]; //두 지점 사이의 거리를 더함
            	if(res<min) min=res; //두 값중에 더 작은 값을 택함.(최소거리이므로)
			}
        }
    }
	cout<<min-2; //시작지점을 1부터 계산했으므로 각각 1씩 총 2를 뺀 값 출력
    return 0;

} 

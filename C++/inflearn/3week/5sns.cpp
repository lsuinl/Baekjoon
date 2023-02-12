#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={-1, 0, 1, 0}; //x이동
int dy[4]={0, 1, 0, -1}; //y이동
int main() { 
	ios_base::sync_with_stdio(false); //입출력을 빠르게
	//freopen("input.txt", "rt", stdin);
	int n; 
	cin>>n; //방의 너비
	vector<vector<int>> pan(n+1, vector<int>(n+1, 0)); //2차원벡터로 pan을 만들어줍니다. 크기는 방의너비보다1 큰 상태이고 모두 0으로 초기화!
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>pan[i][j]; //pan에 값을 입력받아줍니다.
		}
	}
	int sx, sy, ex, ey;
	cin>>sx>>sy; //톰의위치
	cin>>ex>>ey; //줴릐의위치
	queue<pair<int, int> > Q; //좌표를 입력받을 한 쌍의 큐.
	Q.push(make_pair(sx, sy)); //큐에 톰의 위치를 입력해요.
	pan[sx][sy]=2; //시작한 부분은 2로 설정해요(왜냐면 장애물없는곳을 지금0,있는곳을1로 설정한 상태거든요)
	//앞으로 0이 있는 자리에 모두 최소 이동거리를 넣어줄겁니다. 근데 시작이 2라서 원래 이동거리의 -2해야해요
	while(!Q.empty()){
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++){
			//좌표 하나씩 넣어가기
			int xx=x;
			int yy=y;
			while(xx+dx[i]>0 && xx+dx[i]<=n && yy+dy[i]>0 && yy+dy[i]<=n && pan[xx+dx[i]][yy+dy[i]]!=1){  //***s장애물을 만나거나 벽을 만날때까지 계속해요
				if(pan[xx+dx[i]][yy+dy[i]]==0){ //방문여부를 체크해보아요(0이면 방문x)
					Q.push(make_pair(xx+dx[i], yy+dy[i])); //해당좌표는 q에 다시 넣어줘요
					pan[xx+dx[i]][yy+dy[i]]=pan[x][y]+1;	//좌표에는 원래 이동거리에서 1을 더한값을 저장해두어요
				}
				xx=xx+dx[i];
				yy=yy+dy[i];
			
		}
	}
	if(pan[ex][ey]==0) cout<<"-1"; //만약 제리까지 가는 좌표가 0이면 이동할 수 없는 공간이니까 -1이 됩니다.
	else cout<<pan[ex][ey]-3; //0이 아니면 해당 좌표에 입력되어있는 값을 출력해요. 값은 
	return 0;
}

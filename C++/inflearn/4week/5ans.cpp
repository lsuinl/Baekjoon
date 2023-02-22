#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

int dx[4]={0, 1, 0, -1}; 
int dy[4]={-1, 0, 1, 0};
int board[31][31], dist[31][31];

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}

};
queue<Loc> Q;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>board[i][j];
			if(board[i][j]==2) Q.push(Loc(i, j));
		}
	}
	while(!Q.empty()) {
		int x=Q.front().x;
		int y=Q.front().y;
		Q.pop();
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n && board[nx][ny]==0){
				board[nx][ny]=1;
				dist[nx][ny]=dist[x][y]+1;
				Q.push(Loc(nx, ny));
				res=max(res, dist[nx][ny]);
			}
		}
	}
	cout<<res;
	return 0;
}

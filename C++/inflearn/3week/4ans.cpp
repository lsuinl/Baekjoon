#include <iostream>
#include <algorithm>

using namespace std;

int sw, p[2][81], h[10][10], y[10][10], g[10][10], cnt=0, pan[10][10];
int find(int x, int y){ //
	return x/3*3+y/3;
}
void DFS(int L){
	if(L==cnt){ //입력받은 숫자가.. 0의 개수와 같아지면요 다한거니까요
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<pan[i][j]<<" "; //스도쿠를 출력합시다!.
			cout<<"\n";
		}
		return;
	}
	int xx=p[0][L]; //0을 입력받은 좌표를 하나씩 검사해보아요
	int yy=p[1][L];
	int gg=find(xx, yy); //3*3v판 검사는 특별히 이걸로 해요
	for(int i=1; i<=9; i++){
		//0을입력받은 그 공간에 0~9까지를 하나씩 대입해서 검사해요
		if(h[xx][i]==0 && y[yy][i]==0 && g[gg][i]==0){ //당신은 세가지 조건에 만족하십니까?
			h[xx][i]=y[yy][i]=g[gg][i]=1; //만족한다면 세가지 조건을 모두 만족한 당신에게 세가지의 합격목걸이를 드려요. 1
			pan[xx][yy]=i; //판에 입력해줍니다. 답을!!
			DFS(L+1); //다음 0번좌표로 가요
			pan[xx][yy]=0; //0으로만들어두어요.. 막히면요(맞나요?몰라요)
			h[xx][i]=y[yy][i]=g[gg][i]=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); //입출력시간을 단축해요
	//freopen("input.txt", "rt", stdin); 
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>pan[i][j]; //스토쿠를 입력받아요.
			if(pan[i][j]==0){ //0을 입력받게되면.
				p[0][cnt]=i; //0이있는 x좌표.
				p[1][cnt++]=j; //0이있는y좌표. 를 저장해주어요
			}
			else{//0을 입력받은게 아니라면
				h[i][pan[i][j]]=1; //가로줄에 입력받은 숫자가 있다는 것을 넣어줘요
				y[j][pan[i][j]]=1; //세로줄에 입력받은 숫자가 어쩌고
				g[find(i, j)][pan[i][j]]=1; //3*3 스도쿠 정사각형안에 입력받은 어쩌고
			}
		}
	}
	DFS(0);
	return 0;
}

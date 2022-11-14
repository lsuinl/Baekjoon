#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[50][50];
bool visited[50][50];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int m, n, k;

void bfs(int y, int x)
{
	visited[y][x] = 1; //해당 위치 방문함!
	queue<pair<int, int>>q; //int형 두개를 쌍으로 가지는 queue
	q.push(make_pair(y, x)); //x,y쌍을 q에 저장
	while (!q.empty())
	{
		y = q.front().first; //y좌표 저장
		x = q.front().second;//x좌표 저장
		q.pop(); //삭제
		for (int i = 0; i < 4; i++)
		{
			int ny = y + yy[i];  
			int nx = x + xx[i]; 
            //해당 값이 지정 좌표 범위안에 있는지를 검사
			if (ny >= 0 && nx >= 0 && nx < m && ny < n) { 
                //배추가 있는지, 있다면 방문한 적이 있는지를 검사
				if (map[ny][nx] == 1 && visited[ny][nx] == 0)
				{
					q.push({ ny,nx }); //없으면 새롭게 검사시작
					visited[ny][nx] = 1;//방문체크
				}
			}
		}
    }
}

int main()
{
	int t;
	cin >> t;

	for(int a=0;a<t;a++)
	{
        int x, y,ans=0;
		memset(map, 0, sizeof(map));//해당 변수를 모두 0으로 초기화해줌
		memset(visited, 0, sizeof(visited)); //위와 같음
		cin >> m >> n >> k; 
		for (int i = 0; i < k; i++) //
		{
			cin >> x >> y; 
			map[y][x] = 1; //배추가 심어진 곳에 값 넣기
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
                //배추가 심어져있는데 방문하지 않았다면
				if (map[i][j] == 1 && visited[i][j] == 0) 
				{
					bfs(i, j); //bfs실행.
					ans++; // 필요한 지렁이 한마리 추가
				}
			}
		}
		cout << ans << endl; //총 결과 출력
	}
}
	
// #include <iostream>
// #include <queue>
// #include <vector>
// //상하좌우검사
// using namespace std;
// bool visited[5050]={false,};
// vector<int> suin[5050]={0,}; 

// int bfs(int start){
//     if(visited[5050]|| suin[start]!=0) {return 0;} //이미 방문했거나 없는 곳인경우
//     queue<int> q;
//     q.push(start);
//     visited[start]=true;
//     while(!q.empty()){
//         int x=q.front();
//         q.pop();
//         for(int i=0;i<suin[start].size();i++){
//             int y=suin[x][i];
//             if(!visited[y]){
//                 q.push(y);
//                 visited[y]=true;
//             }
//         }
//     }
//     return 1;
// }

// int main(){
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int m,n,k,result;
//         cin>>m>>n>>k;

//         for(int j=0;j<k;j++){
//             int x,y;
//             cin>>x>>y;
//             suin[x*100+y].push_back(((x+1)*100)+y);
//             suin[((x+1)*100)+y].push_back(x*100+y);
//             suin[x*100+y].push_back(((x-1)*100)+y);
//             suin[((x-1)*100)+y].push_back(x*100+y);
//             suin[x*100+y].push_back((x*100)+(y+1));
//             suin[(x*100)+(y+1)].push_back(x*100+y);
//             suin[x*100+y].push_back((x*100)+(y-1));
//             suin[(x*100)+(y-1)].push_back(x*100+y);
//         }
//         for(int j=0;j<m*100+n;j++)
//             result+=bfs(j); //하나씩 검사
//         cout<<result<<'\n';
//     }
//     return 0;
// }
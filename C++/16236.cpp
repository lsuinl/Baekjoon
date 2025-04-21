#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, result=0; //기본값, 결과
int maps[21][21];//지도
pair<int,pair<int,int>> shark={2,{0,0}}; //상어 현황
multimap<int, pair<int, int>> fish; //물고기 현황

int bfs(pair<int,int> end){
    bool visited[21][21]={false,};

    queue<pair<int,pair<int,int>>> q; //이동비용, 현재좌표
    pair<int,int> dxy[4]={{1,0},{0,1},{-1,0},{0,-1}}; //4방향 체크

    q.push({0,shark.second});
    visited[shark.second.first][shark.second.second]=true;

    while(!q.empty()){
        int cost = q.front().first;
        pair<int,int> cur = q.front().second;
        q.pop();
        if(cur==end) return cost;
        for(int i=0;i<4;i++){
            pair<int,int> xy ={cur.first+dxy[i].first,cur.second+dxy[i].second};
            if(xy.first>-1 && xy.first<n && xy.second>-1 && xy.second<n&& visited[xy.first][xy.second]==false){
                if(maps[xy.first][xy.second]<=shark.first){ //상어와의 크기비교
                    visited[xy.first][xy.second]= true;
                    q.push({cost+1,xy});
                }
            }
        }
    }

    return 1e9;
}

void game(){
    int eat=0;

    while(true){
        int min =1e9;
        multimap<int, pair<int, int>>::iterator minFish=fish.end();
        for(auto e=fish.begin();e!=fish.end();e++){
            if(e->first<shark.first){ //작으면 머글수있다
                int curDis = bfs(e->second); //먹을방법
                if(min>curDis){
                    min=curDis;
                    minFish=e;
                }
                else if(min==curDis){
                    int minx=minFish->second.first ,miny=minFish->second.second; 
                    int ex=e->second.first ,ey=e->second.second; 
                    if(minx>ex||(minx==ex && miny>ey)){
                        minFish=e;
                    }
                }
                }
            else{
             break;
            }
            }
            if (minFish == fish.end() || min == 1e9) break;
            eat++; //머겅
            result+=min; //이동시간추가
            shark.second=minFish->second; //이동
            fish.erase(minFish); //머것으니 사라졍
            maps[shark.second.first][shark.second.second] = 0;
            if(eat==shark.first){ 
                shark.first++;
                eat=0;
            }
        }
    }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
            if(maps[i][j]==9){
                shark.second={i,j};
                maps[i][j] = 0;
            }
            else if(maps[i][j]!=0){
                fish.insert({maps[i][j],{i,j}});
            }
        }
    }
    game();
    cout<<result;
    return 0;
}
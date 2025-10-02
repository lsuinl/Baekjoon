#include <iostream>
using namespace std;

int r,c,t, result=0;
int map[50][50];
pair<int,int> freshs;


//미세먼지 확산
void dust(){
    int newData[50][50]={0,};
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            if(map[x][y]>0){
                int count=0;
                for(int i=0;i<4;i++){
                    if(x+dx[i]>-1 && x+dx[i]<r && y+dy[i]>-1 && y+dy[i]<c){ //범위 체크하기
                        if(map[x+dx[i]][y+dy[i]]==-1) continue;
                        else{
                            newData[x+dx[i]][y+dy[i]] += map[x][y]/5;
                            count++;
                        }
                    }
                }
                newData[x][y]+= map[x][y]-(map[x][y]/5)*count;
            }
        }
    }

    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            map[x][y]=newData[x][y];
        }
    }
    map[freshs.first][freshs.second]=-1;
    map[freshs.first-1][freshs.second]=-1;
}

//공기청정기 작동
//왼, 오, 위, 아래
int fresh(int startX,int startY, int empA,int forward){
    int empB=0;
    switch (forward)
    {
    case 0://왼
        while(startY>0){ 
            empB = map[startX][startY-1];
            if(empB==-1) break;
            map[startX][startY-1]=empA;
            empA=empB;
            startY--;
        }
        break;
    case 1://오
        while(startY<c-1){ 
            empB = map[startX][startY+1];
            if(empB==-1) break;
            map[startX][startY+1]=empA;
            empA=empB;
            startY++;
        }
        break;
    case 2://위
        while(startX>0){ 
            empB = map[startX-1][startY];
            if(empB==-1) break;
            map[startX-1][startY]=empA;
            empA=empB;
            startX--;
        }
        break;
    case 3://아래
        while(startX<r-1){
            empB = map[startX+1][startY];
            if(empB==-1) break;
            map[startX+1][startY]=empA;
            empA=empB;
            startX++;
        }
        break;
    }

    return empB;
}

int main(){

    cin>>r>>c>>t;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
            if(map[i][j]==-1) freshs={i,j};
        }
    }
    
    for(int i=0;i<t;i++){
        dust();
        int emp= 0;
        //오,위,왼,아
        emp=0;
        emp = fresh(freshs.first-1,freshs.second,emp,1);
        emp = fresh(freshs.first-1,c-1,emp,2);
        emp = fresh(0,c-1,emp,0);
        emp = fresh(0,0,emp,3);
        
        //오,아,왼,위
        emp=0;
        emp = fresh(freshs.first,freshs.second,emp,1);
        emp = fresh(freshs.first,c-1,emp,3);
        emp =fresh(r-1,c-1,emp,0);
        fresh(r-1,0,emp,2);
        map[freshs.first-1][freshs.second+1]=0;
        map[freshs.first][freshs.second+1]=0;
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result+=map[i][j];
        }
    }
    cout<<result+2;

    return 0;
}
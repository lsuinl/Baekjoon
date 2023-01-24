#include <iostream>
#include <vector>
//비트연산을 활용함.
using namespace std;

int n,d,k;// n:학생수, d:양념종류, k:사용할양념개수
int res=0;

void DFS(int L, int s, int bit, vector<int> &st, vector<int> &pow){
    if(L==k){//L과 사용할 양념개수가 같으면
        int cnt=0; //카운트.
        for(int i=1;i<=n;i++) if((bit&st[i])==st[i]) cnt++; //해당 학생이 먹을 수 있는지를 비트연산으로 체크하고 카운트
        res=max(res,cnt); //먹을 수 있는 학생이 더 많은 값을 저장.
    }
    else{
        for(int i=s;i<=d;i++){ 
            DFS(L+1,i+1,bit+pow[i],st,pow);
        }
    }
}

int main(){
    cin>>n>>d>>k;
    vector<int> st(n+1), pow(d+1); //st:학생별 선호 양념 저장 pow:양념번호저장
    pow[1]=1; //
    for(int i=2;i<=d;i++) pow[i]=pow[i-1]*2; //양념번호=2의 가중치(1,2,4,8...)2진수.
    for(int i=1;i<=n;i++){
        int m,num; //m:학생이 먹고싶은 양념 개수
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>num; //양념번호
            st[i]+=pow[num];//학생별로 양념번호 를 더해줌.
            //만약 1번학생이 2번,3번 양념을 원한다면, st[0]에 2번(2),3번(4)양념번호를 더한 6(0110)을 저장함
        }
    }
    DFS(0,1,0,st,pow);//DFS 실행.
    cout<<res;
    return 0;
}
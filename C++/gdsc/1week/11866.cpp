#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,K; //입력받을 변수
    vector<int> suin; //벡터
    cin>>N>>K; //입력받음

    for(int i=1;i<=N;i++) //벡터에 값 넣기
        suin.push_back(i);
    
    int point=0; //인덱스를 가리킬 변수

    cout<<"<"; //출력시작
    for(int i=1;i<=N;i++){ //N개 뽑아낼동안 반복.
        point+=K-1; //인덱스는 0부터 시작하므로.
        while(suin.size()-1<point) //원형. 범위를 넘으면 0번부터 다시.
            point-=suin.size();
        if(i==N){ //N개를 전부 뽑아내면 반복문 탈출
            cout<<suin[point]; //
            break;
        }
        cout<<suin[point]<<", "; //출력
        suin.erase(suin.begin()+point); //출력한 값 벡터에서 삭제

    }
    cout<<">"; //출력종료
    
    return 0;
}
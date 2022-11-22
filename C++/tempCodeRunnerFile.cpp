#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); //내림차순정렬
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>> q;

    int n,vote,result=0;

    cin>>n;
    cin>>vote;

    int dasom=vote; //1번의 득표수
    q.push(vote);
    for(int i=1;i<n;i++){ //입력받아서 정렬하기
        int vote;
        cin>>vote;
        q.push(vote);
    }

    int max=q.top(); //가장 큰 값 저장

    while(q.size()>1 && dasom<=max){ //1번득표수가 더 많아지는 그날까지
        max=q.top(); //가장 큰 수가 max에 저장
        dasom+=1; //1번에 1추가
        max-=1; //가장 큰 수에 -1
        q.pop(); //가장 큰 수를 지우고,
        q.push(max); //그 안에 가장 큰수-1을한 값을 넣어줌
        result++; //횟수카운트
    }

    cout<<result;

    return 0;
}
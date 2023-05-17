//Lv1. 실패율
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
static bool comp(pair<int, double>& a, pair<int, double>& b){
    if(a.second==b.second) return a.first <b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> fail;
    
    for(int i=1;i<=N;i++){ //1스테이지부터 n스테이지까지
        int number=0;
        int size=stages.size();
        for(int j=0;j<stages.size();j++){ //한명씩 체크해주어요
            if(i==stages[j]){ //실패한사람발견
               stages.erase(stages.begin() + j); //낙오시킵니다
               j--;
                number++; //실패율 체크
            }
        }
        fail[i]=(number!=0 && size!=0)? double(number)/size: 0; //총 실패율 map형태로 저장
    }
    
    
    vector<pair<int,  double>> v(fail.begin(), fail.end()); //벡터값에 map옮겨적기
    sort(v.begin(), v.end(), comp); //순서대로 정렬
    for(auto e: v){
        answer.push_back(e.first); //정렬된대로 결과에 삽입
    }
    return answer;
}


int main(){
    vector<int> suin={2,1,2,6,2,4,3,3};
    solution(5,suin);
    return 0;
}
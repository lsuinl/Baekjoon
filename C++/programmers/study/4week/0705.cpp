#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(),greater<>());
    for(int i=0;i<score.size();i+=m){
        if(i+m>score.size())
            break;
        answer+=score[i+m-1]*m;
    }
    return answer;
}

int main(){
    int k=3;
    int m=4;
    vector<int> score={1, 2, 3, 1, 2, 3, 1};
    solution(k,m,score);
    return 0;
}
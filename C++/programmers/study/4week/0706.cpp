#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> line;
    for(int i=0;i<k;i++){
        if(i==score.size()) break; //헉
        line.push_back(score[i]);
        sort(line.begin(),line.end());
        answer.push_back(line[0]);
    }
    for(int i=k;i<score.size();i++){
            line.push_back(score[i]);
            sort(line.begin(),line.end());
            line.erase(line.begin());
            answer.push_back(line[0]);
    }
    return answer;
}


int main(){
    int k=4;
    vector<int> score = {0, 300, 40, 300, 20, 70, 150, 50, 500, 1000};
    solution(k,score);
    return 0;
}
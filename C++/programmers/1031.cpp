//lv1.달리기경주

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for(int i=0;i<callings.size();i++){
        int index=find(players.begin(), players.end(), callings[i]) - players.begin();
        players.insert(players.begin()+index-1,callings[i]);
        players.erase(players.begin()+index+1);
    }
    return answer;
}

int main(){
    vector<string> players={"mumu", "soe", "poe", "kai", "mine"};
    vector<string> callings={"kai", "kai", "mine", "mine"};
    solution(players,callings);
    return 0;
}
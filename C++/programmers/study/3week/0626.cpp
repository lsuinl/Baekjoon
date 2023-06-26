#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     for(int i=0;i<participant.size();i++){
//         for(int j=0;j<completion.size();j++){
//             if(participant[i]==completion[j]){
//                 participant.erase(participant.begin()+i);
//                 completion.erase(completion.begin()+j);
//                 i--;
//                 break;
//             }
//         }
//     }
//     return participant.front(); 
// }
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> map; //해시만들기
    for (auto player : participant) 
    {
        if (map.end() == map.find(player)) //중복되지 않는다면
            map.insert(make_pair(player, 1)); //새로운 값으로 해시에 추가해준다. 한명이니까 1
        else
            map[player]++; //중복되는 이름이면 값을 1 추가해서 한명 더 있다는 것을 표기
    }

    for (auto player : completion)
        map[player]--; //해당 선수의 이름의 값을 제거

    for(auto player : participant)
        if (map[player] > 0) //1명이 존재하는 해시값을 탐색하여 존재하면 해당 값을 결과로 리턴
        {
            answer = player;
            break;
        }
    return answer;
}


int main(){
    vector<string> participant={"leo", "kiki", "eden"};
    vector<string> compeltion={"eden", "kiki"};
    string suin = solution(participant,compeltion);
    cout<<suin;
    return 0;
}
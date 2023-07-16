#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char,int> map;
    //키입력 최솟값 지정하기(1회부터)
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
                    if(map[keymap[i][j]]==0) map[keymap[i][j]]= j+1;
            else map[keymap[i][j]]= map[keymap[i][j]]<(j+1) ?map[keymap[i][j]]:(j+1);
        }
    }
    //문장만들기.
    for(int i=0;i<targets.size();i++){
        int result=0;
        for(int j=0;j<targets[i].size();j++){
            result+=map[targets[i][j]];
                //민들 수 없는 문자열
            if(map[targets[i][j]]==0){
                result=-1;
                break;
            }
}
        answer.push_back(result);
}
    
    return answer;
}
int main(){
    vector<string> keymap={"ABACD", "BCEFD"};
    vector<string> targets={"ABCD","AABB"};
    solution(keymap,targets);
    return 0;
}
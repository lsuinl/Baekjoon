#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int orders(int e){
        switch (e)
    {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_set<int> set;
    int min=0, max=0;
    for(int a:win_nums){ //해시 만들기
        set.insert(a);
    }
    for(int a:lottos){
        if(a==0){
            max++;
        }
        else if(set.find(a)!=set.end()){
            set.erase(a);
            min++;
        }
    }
    max+=min;
    answer.push_back(orders(max));
    answer.push_back(orders(min));
    return answer;
}


int main(){
    vector<int> lottos={44, 1, 0, 0, 31, 25};
    vector<int> win_nums={31,10,45,1,6,19};
    solution(lottos,win_nums);
    return 0;
}
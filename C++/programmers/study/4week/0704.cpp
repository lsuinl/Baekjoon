#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(),lost.end());
    for(int i=0;i<lost.size();i++){
        if(reserve.end()!=find(reserve.begin(),reserve.end(),lost[i])) {//여분의 체육복이 있는 친구가 도난당한 경우
            cout<<"여분";
            reserve.erase(find(reserve.begin(),reserve.end(),lost[i]));
            lost.erase(lost.begin()+i);
            i--;
        }
    }
 for(int i=0;i<lost.size();i++){
    if(reserve.end()!=find(reserve.begin(),reserve.end(),lost[i]-1)){ //앞번에있으면,,
            cout<<"앞번"<<lost[i]-1;
            reserve.erase(find(reserve.begin(),reserve.end(),lost[i]-1));
            lost.erase(lost.begin()+i);
            i--;
        }
        else if(reserve.end()!=find(reserve.begin(),reserve.end(),lost[i]+1))
        {
            cout<<"뒷번"<<lost[i]+1;
            reserve.erase(find(reserve.begin(),reserve.end(),lost[i]+1));
            lost.erase(lost.begin()+i);
            i--;
        }
 }
    answer=n-lost.size();
    return answer;
}

int main(){
    int n=5;
    vector<int> lost= {2,4};
    vector<int> reserve = {3};
    cout<<solution(n,lost,reserve);
    return 0;
}
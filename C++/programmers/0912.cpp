#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    deque<int> q;
    copy(people.begin(), people.end(), std::inserter(q, q.end()));

    while(q.size()>0){
        int kg=limit;
        kg-=q[q.end()];
        q.pop_back();
        if(q.size()>0 && kg>=q[0]){
                kg-=q[0];
                q.pop_front();
        }
        answer++;
    }
    return answer;
}

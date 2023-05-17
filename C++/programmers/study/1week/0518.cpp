//Lv1.모의고사

#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one={1,2,3,4,5}, two={2,1,2,3,2,4,2,5}, three={3,3,1,1,2,2,4,4,5,5};
    int grade1=0, grade2=0, grade3=0;
    for(int i=0;i<answers.size();i++){
        if(one[i%5]==answers[i]) grade1++;
        if(two[i%8]==answers[i]) grade2++;
        if(three[i%10]==answers[i]) grade3++;
    }
    int maxx=max(grade1,max(grade2,grade3));
    if(grade1==maxx) answer.push_back(1);
    if(grade2==maxx) answer.push_back(2);
    if(grade3==maxx) answer.push_back(3);
    return answer;
}
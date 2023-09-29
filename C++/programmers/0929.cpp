#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<string, int> check={};
    for(int i=0;i<survey.size();i++){
        if(choices[i]>4){//앞
            check[survey[i]]-=(choices[i]-4);
        }
        else if(choices[i]<4){ //뒤
            if(choices[i]==1) choices[i]=3;
            else if(choices[i]==3) choices[i]=1;
            check[survey[i]]+=choices[i];
        }
    }
    
    if(check["RT"]-check["TR"]<0) answer.push_back('T');
    else answer.push_back('R');
    if(check["CF"]-check["FC"]<0) answer.push_back('F');
    else answer.push_back('C');
    if(check["JM"]-check["MJ"]<0) answer.push_back('M');
    else answer.push_back('J');
    if(check["AN"]-check["NA"]<0) answer.push_back('N');
    else answer.push_back('A');
    return answer;
}

int main(){
    vector<string> survey;
    vector<int> choices;

    cout<<solution(survey, choices);
}
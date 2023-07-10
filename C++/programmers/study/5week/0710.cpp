#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> map;    

    for(int i=0;i<terms.size();i++){
            map.insert(make_pair(terms[i][0], stoi(terms[i].substr(2))));
    }

    int year=stoi(today.substr(0,4));
    int month=stoi(today.substr(5,6));
    int day= stoi(today.substr(8,9));

    for(int i=0;i<privacies.size();i++){
        int useryear=stoi(privacies[i].substr(0,4));
        int usermonth=stoi(privacies[i].substr(5,6));
        int userday= stoi(privacies[i].substr(8,9));

        //년도
        int sum = (year-useryear)*12;
        //월
        if(sum>0){
            if(month<usermonth) sum -= (usermonth-month);
            else if(month>usermonth) sum+= (month-usermonth); 
        }
        else sum+=month-usermonth;
        //일
        sum = userday<=day ? sum+1:sum;
        
        //최종 비교
        if(map[privacies[i][11]]<sum) answer.push_back(i+1);
    }
    return answer;
}

int main(){
    string today="2022.05.19";
    vector<string> terms={"A 6", "B 12", "C 3"};
    vector<string> privacies={"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    solution(today,terms,privacies);
    return 0;
}
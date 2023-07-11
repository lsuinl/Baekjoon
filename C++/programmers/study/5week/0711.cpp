#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
//aya woo ye ma
int solution(vector<string> babbling) {
    int answer=0;
    for(int i=0;i<babbling.size();i++){
        string str=babbling[i];
        str=regex_replace(str, regex("aya"), "1");
        str=regex_replace(str, regex("ye"), "2");
        str=regex_replace(str, regex("woo"), "3");
        str=regex_replace(str, regex("ma"), "4");
        //맞지않는 문자열 섞인경우
       if(regex_search(str,regex("[a-z]"))!=0) {
           continue;
       }
        //중복이 아닌경우
        if(str.find("11")==string::npos&&str.find("22")==string::npos&str.find("33")==string::npos&str.find("44")==string::npos)
        answer++;
    }
    cout<<answer;
    return answer;
}
int main(){
    vector<string> babbling={"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    solution(babbling);
    return 0;
}

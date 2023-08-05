//최댓값과 최솟값
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    while(s.find(' ')!=string::npos){
        answer+= toupper(s[0]);//첫글자는 대문자로
         //나머지 글자는 소문자로
        string lowers= s.substr(1,s.find(' '));
        for(int i=0;i<lowers.length();i++)
            answer+=tolower(lowers[i]);
        s=s.substr(s.find(' ')+1); //잘라두기
    }
    if(s.length()>0){
        answer+= toupper(s[0]);
        if(s.length()>1){
            string lowers= s.substr(1);
            for(int i=0;i<lowers.length();i++)
                answer+=tolower(lowers[i]);
        }
    }
    return answer;
}

int main(){
    string s = "3people unFollowed me";
    cout<<solution(s);
}
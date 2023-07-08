#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char word;
    int wordcount=0, anothercount=0;
    for(int i=0;i<s.length();i++){
        if(i==0) word=s[0];
        //워드개수카운트
        if(s[0]==s[i]) wordcount++;
        else anothercount++;
        
        //둘의 개수가 같아지는 순간        
        if(wordcount==anothercount){
            s=s.substr(i+1,s.length());
            i=-1;
            answer++;
            wordcount=0;
            anothercount=0;
        }
        else if(i==s.length()-1)
            answer++;
    }
    return answer;
}

int main(){
    string s="abracadabra";
    cout<<solution(s);
    return 0;
}
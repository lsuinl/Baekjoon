#include <string>
#include <iostream>

using namespace std;

int caculator(string dartResult, int number){
        int sum=0;
        if(dartResult[number]=='S') {//문자면 앞에꺼 합산하여 계산.
                sum=dartResult[number-1]-'0';
                if(dartResult[number-2]=='1') sum=10;
            }
            else if(dartResult[number]=='D'){
                sum=(dartResult[number-1]-'0')*(dartResult[number-1]-'0');
                if(dartResult[number-2]=='1') sum=100;
            }
            else if(dartResult[number]=='T'){
                sum=(dartResult[number-1]-'0')*(dartResult[number-1]-'0')*(dartResult[number-1]-'0');
                if(dartResult[number-2]=='1') sum=1000;
            }
    return sum;
}

int solution(string dartResult) {
    int answer = 0;
    int number=0;
    for(int i=dartResult.size()-1;i>=0;i--){
        if(dartResult[i]=='S' || dartResult[i]=='D'|| dartResult[i]=='T'){
            number=caculator(dartResult,i);
            
            if(dartResult[i+1]=='#')
                number*=(-1);
            else if(dartResult[i+1]=='*'){
                number*=2;
            }
            if(dartResult[i+4]=='*'|| dartResult[i+3]=='*'){
                number*=2;
            }
                answer+=number;
        }
    }
    
    return answer;
}
int main(){
    string str;
    cin>>str;
    cout<<solution(str);
    return 0;
}
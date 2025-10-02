#include <iostream>
#include <string>

using namespace std;

string s, result;

void backExcpress(int start){
    for(int i=start;i<s.length();i++){
        char word = s[i];
        switch (word)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            result.push_back(s[i-1]);
            result.push_back(s[i+1]);
            result.push_back(s[i]);
            break;
        
        default:
            break;
        }
    }
}

int main(){
    cin>>s;
    backExcpress(0);
    cout<<result;
    return 0;
}

//A*(B+C)

//A 
//BC+
//*

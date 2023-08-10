#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open=0;
    int end=0;
    bool answer = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            open++;
        else
            end++;
        if(open<end){
            answer=false;
            break;
        }
    }
    if(open==end) answer=true;
    else answer=false;
    cout << "Hello Cpp" << endl;

    return answer;
}
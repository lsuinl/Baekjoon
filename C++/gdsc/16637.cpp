#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
//https://jaimemin.tistory.com/1454
//DFS

int N;
string s;
int result =INT_MIN;

int caculate(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}

void check(int idx, int value){
    if(idx>=N){ 
        result=max(result,value);
        return;
    }
    char op = idx>=1?s[idx-1]:'+';
    int temp=caculate(value,s[idx]-'0',op);

    check(idx+2, temp);
    if(idx<N-2){
        temp=caculate(s[idx]-'0',s[idx+2]-'0',s[idx+1]);
        temp=caculate(value,temp,op);
        check(idx+4,temp);
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin>>N;
    cin>>s;
    check(0,0);
    cout<<result<<"\n";
    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    while(1){
        getline(cin, n);
        bool no=false;
        stack<char> stacks;
        if(n[0]=='.') break; //종료 조건
        for(int i=0;i<n.length();i++){
            if(n[i]=='(' || n[i]=='[') stacks.push(n[i]);
            else if(n[i]==')'|| n[i]==']'){
                if(stacks.empty()){ no=true; break;}
                else{
                    if(n[i]==')'&& stacks.top()=='(') stacks.pop();
                    else if(n[i]==']'&& stacks.top()=='[') stacks.pop();
                    else { no=true; break;}
                }
            }
        }          
        if(no==false && stacks.empty()) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
    return 0;
}
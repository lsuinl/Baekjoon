#include <iostream>
#include <stack>

using namespace std; 


int main(){
    int max=0;
    stack<int> stacks;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a;  cin>>a;
        stacks.push(a);
        
    }
    while(!stacks.empty()){
        if(max>stacks.top()){

        }
    }
    return 0;
}
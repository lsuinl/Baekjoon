#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string answer="";
    cin>>n;
    if(n==1) answer="ascending";
    else if(n==8)answer="descending";
    else answer="mixed";

    for(int i=2;i<=8;i++){
        cin>>n;
        if(answer=="ascending" && n!=i) answer="mixed";
        else if(answer=="descending" && n!=(9-i)) answer="mixed";
    }
    
    cout<<answer;
    
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result=0;
    int mushroom[10];
    for(int i=0;i<10;i++){
        cin>>mushroom[i];
    }
    for(int i=0;i<10;i++){
        result+=mushroom[i];
        if((result+mushroom[i+1])>=100){
            result=abs(result-100)>abs(result+mushroom[i+1]-100)? result+mushroom[i+1]:result;
            break;
        }
    }
    
    cout<<result;

    return 0;
}

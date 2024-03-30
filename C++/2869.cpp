#include <iostream>

using namespace std;

int main(){
    int a,b,v,day=0;
    cin>>a>>b>>v;
    
    day = v%(a-b)==0? v/(a-b) : v/(a-b)+1;
    day-=a/(a-b);

    day-=2;
    for(int i=0;i<5;i++){
        if(day*(a-b)+a>=v) {
            day++;
            break;
        }
        day++;
    }
    cout<<day;
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int tri[3];
    while(1){
        cin>>tri[0]>>tri[1]>>tri[2];
        if(tri[0]==0&&tri[1]==0&&tri[2]==0) break;
        sort(tri,tri+3);
        int ab=(pow(tri[0],2)+pow(tri[1],2));
        int c=pow(tri[2],2);
        if(ab==c)
            cout<<"right"<<"\n";
        else
            cout<<"wrong"<<"\n";
    }
    return 0;
}

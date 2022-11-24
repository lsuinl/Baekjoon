#include <iostream>

using namespace std;

int main(){
    int n,result=1,i=1;
    cin>>n;
    while(n>0){
        if(n==1){
            break;
        }
        n-=i*6;
        result++;
        i++;
    }
    cout<<result;
    return 0;
}

// 1=0
// 첫바퀴=2~7 =6=2 
// 두번째바퀴=8~19=12=3
// 세번째=20~37=18=4
// 27개
// ...
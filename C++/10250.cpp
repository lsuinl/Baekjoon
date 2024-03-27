#include <iostream>

using namespace std;

int main(){
    int t,h,w,n;
    cin>>t;
    for(int i=0;i<t;i++){
        int answer=0;
        cin>>h>>w>>n;
        //나머지, 몫
        int one =n%h;
        if(one==0) one=h; 
        one*=100;
        int two =n%h==0 ?n/h : n/h+1;
        answer=one+two;
        cout<<answer<<'\n';
    }
    return 0;
}

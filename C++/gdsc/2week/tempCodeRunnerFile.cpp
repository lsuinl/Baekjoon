#include <iostream>

using namespace std;

int main(){
    int T,A,B;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        int max=A>B?A:B;
        int min=A>B?B:A;
        int plus=max;
        while(1){
            if(max%min==0) break;
            max+=plus;
        }
        cout<<max;
    }
    return 0;
}
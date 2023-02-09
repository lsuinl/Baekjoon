#include <iostream>

using namespace std;

int main(){
    int n;
    int suin=0;
    cin>>n;
    int seat[n];
    for(int i=0;i<n;i++){
        cin>>seat[i];
    }

    for(int i=0;i<n;i++){
        if(seat[i]==0){
            int a=i;
            int result=100;
            while(a!=n){
                if(seat[a]==1){
                    result=(a-i);
                    break;
                }
                a++;
            }
            a=i;
            while(a!=-1){
                if(seat[a]==1){
                    result= result<(i-a)? result:(i-a);
                    break;
                }
                a--;
            }
            suin=result<suin ?suin:result;
        }
    }
    cout<<suin;
    return 0;
}
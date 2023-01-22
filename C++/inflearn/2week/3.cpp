#include <iostream>

using namespace std;

int main(){
    int N,K,result=0;
    cin>>N;
    int time[N];
    for(int i=0;i<N;i++)
        cin>>time[i];
    cin>>K;
    int r=0;
    for(int i=0;i<K;i++){
        if(r>N-1){r=0;}
        for(int j=r;j<N;j++){
            if(time[j]==0 && j==N-1){
                j=-1;
                continue;
            }
            else if(time[j]==0){
                continue;
            }
            else {
                time[j]--;
                r=j+1;
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(time[i]!=0){
            break;
        }
        else if(i==N-1){
            r=-1;
        }
    } 

    cout<<r;

    return 0;
}
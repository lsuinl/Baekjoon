#include <iostream>

using namespace std;

int main(){
    int answer[100][100]={0,};
    int n, m,output=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int stx,sty,enx,eny;
        cin>>stx>>sty>>enx>>eny;
        for(int a=stx-1;a<=enx-1;a++){
            for(int b=sty-1;b<=eny-1;b++){
                answer[a][b]++;
            }
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(answer[i][j]>m) output++;
        }
    }

    cout<<output;
    return 0;
}
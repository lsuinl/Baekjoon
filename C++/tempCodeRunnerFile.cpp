#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int tri[n][n];
    int result[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>tri[i][j];
        }
    }
    for(int i=0;i<n;i++){ //첫줄
        result[n-1][i]=tri[n-1][i];
    }

    for(int i=n-2;i==0;i--){
        for(int j=0;j<i;j++){
             if(result[i+1][j]<result[i+1][j+1])
                result[i][j]=tri[i][j]+result[i+1][j+1];
            else
                result[i][j]=tri[i][j]+result[i+1][j];
        }
        
    }
    return 0;
}
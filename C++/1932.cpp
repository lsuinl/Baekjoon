#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int tri[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>tri[i][j];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(tri[i+1][j]<tri[i+1][j+1])
                tri[i][j]+=tri[i+1][j+1];
            else
                tri[i][j]+=tri[i+1][j];
            cout<<tri[i][j]<<i<<j<<endl;
        }
    }

        cout<<tri[0][0];
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int n;
    long long t[36]={1,};
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            t[i]+=t[j]*t[i-j-1];
        }
    }
    cout<<t[n];
    return 0;
}
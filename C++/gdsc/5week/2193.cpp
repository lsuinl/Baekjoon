#include <iostream>

using namespace std;


int main(){
    long long suin[90];
    int N;
    cin>>N;
    suin[0]=1, suin[1]=1;
    for(int i=2;i<N;i++){
        suin[i]=suin[i-1]+suin[i-2];
    }
    cout<<suin[N-1];
    return 0;
}
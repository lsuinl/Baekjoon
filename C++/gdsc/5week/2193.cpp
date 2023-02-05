#include <iostream>

using namespace std;

//3=2 101 100
//4=3 1010 1001 1000
//5=5 10100 10101 10010 10000 10001
//6=8
//... a(n)=a(n-1)+a(n-2)
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
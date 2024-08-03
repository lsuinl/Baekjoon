#include <iostream>

using namespace std;
long long in[1002];

int dps(int n, int num){
    in[num]=(in[num-2]+in[num-1])%10007;
    if(num>=n)return in[num];
    dps(n,num+1);
    return 0;
}
int main(){
    int n;
    cin>>n;
    in[1]=1;
    in[2]=2;
    dps(n,3);
    cout<<in[n]<<endl;
    return 0;
}

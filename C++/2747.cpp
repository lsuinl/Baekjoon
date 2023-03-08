#include <iostream>

using namespace std;
int n;
long long result=0;

void pbonachi(long long a,long long b, int repeat){ //a=n-2, b=n-1
    if(repeat>n){
        cout<<result;
        return;
    }
    else if(repeat<=n){
        result=a+b;
        a=b;
        b=result;
        pbonachi(a,result,repeat+1);
    }
}

int main(){
    cin>>n;
    if(n==0) cout<<0;
    else if(n==1) cout<<1;
    else pbonachi(0,1,2);
    return 0;
}
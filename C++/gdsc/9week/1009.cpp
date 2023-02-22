#include <iostream>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int o=0;o<t;o++){
        long long a,b;
        cin>>a>>b;
        b=(b%4)+4;
        a=(long long)(pow(a,b))%10;
        if(a==0){a=10;}
        cout<<a<<"\n";
    }
    return 0;
} 
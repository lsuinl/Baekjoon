#include <iostream>

using namespace std;

int main(){
    long long a,b,c,result;

    cin>>a>>b>>c;
    int point=10;
    if(b>=1000)
        point = 10000;
    else if(b>=100)
        point=1000;
    else if(b>=10)
        point =100;
    result =a+b-c;
    cout<<result<<endl;
    result = a*point+b-c;
    cout<<result;
    return 0;
}
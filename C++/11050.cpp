#include <iostream>

using namespace std;

int fa(int n){
    if(n==0) return 1;
    return n*fa(n-1);
}


int main(){
    int n,k;
    cin>>n>>k;
    cout<<fa(n)/(fa(n-k)*fa(k));
    return 0;
}
//이런
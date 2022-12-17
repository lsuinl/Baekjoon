#include <iostream>

using namespace std;

int main(){
    int V,A=0,B=0;
    cin>>V;
    for(int i=0;i<V;i++){
        char vote;
        cin>>vote;
        if(vote=='A') A++;
        else B++;
    }

    if(A>B) cout<<"A";
    else if(A<B) cout<<"B";
    else cout<<"Tie";

    return 0;
}
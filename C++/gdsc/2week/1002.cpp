#include <iostream>

using namespace std;

int main(){
    int T,A,B, z;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        //큰 값을 a에, 작은값을 b에
        if(A<B){
            z=A;
            A=B;
            B=z;
        }
        while(A!=B){
            int i=1,j=1;
            A=A*i;
            while(A>B){
                B=B*j;
                j++;
            }
            i++;
        }
        cout<<A;
    }
    return 0;
}
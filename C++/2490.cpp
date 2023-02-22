#include <iostream>

using namespace std;

int main(){
    for(int i=0;i<3;i++){
       int yout,one=0,zero=0;
        for(int j=0;j<4;j++){
            cin>>yout;
            if(yout==0) zero++;
        }
        switch (zero)
        {
        case(0):
            cout<<"E";
            break;
        case(1):
            cout<<"A";
            break;
        case(2):
            cout<<"B";
            break;
        case(3):
            cout<<"C";
            break;
        default:
            cout<<"D";
            break;
        }
        cout<<"\n";
    }
    return 0;
}
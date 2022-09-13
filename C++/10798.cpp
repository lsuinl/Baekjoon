#include <iostream>

using namespace std;

int main(){
    string suin[5];
    for(int i=0;i<5;i++){
        cin>>suin[i];
    }

    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(i<suin[j].length())
                cout<<suin[j].at(i);
        }
    }

    return 0;
}
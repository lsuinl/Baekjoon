#include <iostream>

using namespace std;

int main(){
    string n;
    while(1){
        bool check=true;
        cin>>n;
        if(n=="0")break;
        for(int i=0;i<n.size()/2;i++){
            if(n[i]==n[n.size()-1-i])
                continue;
            else{
                check=false;
                cout<<"no"<<endl;
                break;
            }
        }
        if(check) cout<<"yes"<<endl;;
    }
    return 0;
}
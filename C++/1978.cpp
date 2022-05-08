#include <iostream>

using namespace std;

int main(){
    int n,inp, result=0;

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>inp;
        int find=0;

        for(int j=1;j<=inp;j++){ 
            if(inp%j==0){
                find++;
            }
        }
        if(find==2) 
            result++;
    }

    cout<<result;
    return 0;
}
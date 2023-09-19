#include <iostream>

using namespace std;

int main(){
    int n,result=0;
    cin>>n;
    int line[n-1], coin[n];

    for(int i=0;i<n-1;i++)
        cin>>line[i];

    for(int i=0;i<n;i++)
        cin>>coin[i];

    int min=coin[0];
    int distance=0;
    for(int i=1;i<n;i++){
        distance+=line[i-1];
        if(min>coin[i]){
            cout<<distance*min;
            result+=(distance*min);
            min=coin[i];
            distance=0;
        }
        else if(i+1==n){
            result+=(distance*min);
        }
    }
    cout<<result;

    return 0;
}
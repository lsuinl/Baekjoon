#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long result=0;
    cin>>n;
    long long line[n-1], coin[n];

    for(int i=0;i<n-1;i++)
        cin>>line[i];

    cin>>coin[0];
    long long min=coin[0];
    long long distance=0;
    for(int i=1;i<n;i++){
        cin>>coin[i];
        distance+=line[i-1];
        if(min>coin[i]){
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
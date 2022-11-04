#include <iostream>

using namespace std;

int main(){
    int n, k, result=0;;
    cin>>n>>k;
    int money[n];
    for(int i=0;i<n;i++)
        cin>>money[i];

    for(int i=n-1;i>=0;i--){
        result+=(k/money[i]);
        k=k%money[i];
    }
    cout<<result;
    return 0;
}
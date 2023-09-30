#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int j=1;
    int n,m;
    long long result=1;
    cin>>n>>m;
    for(int i=(n-m);i<=n;i++){
        result*=i;
        if(result/j>1 && j<=m){
            result=result/j;
            j++;
        }
    }
    cout<<result;
    return 0;
}
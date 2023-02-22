#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,result=0;
    int minbundle=6006,minsingle=1001;
    cin>>n>>m;
    int bundle[m], single[m];
    for(int i=0;i<m;i++){
        cin>>bundle[i]>>single[i];
        bundle[i]=min(bundle[i],single[i]*6);
        minbundle=bundle[i]<minbundle ? bundle[i]:minbundle;
        minsingle=single[i]>minsingle ? minsingle:single[i];
    }
    result+=(n/6)*minbundle;
    n=n%6;
    result+=(n*minsingle>minbundle?minbundle:minsingle*n);
    cout<<result;
    return 0;
}
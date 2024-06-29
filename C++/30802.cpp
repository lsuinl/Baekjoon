#include <iostream>

using namespace std;

int main(){
    int n,t,p;
    int tshirt[6];
    int ta=0;
    cin>>n;
    for(int i=0;i<6;i++)
        cin>>tshirt[i];
    cin>>t>>p;
    for(int i=0;i<6;i++)
        ta+=(tshirt[i]/t)+(tshirt[i]%t==0?0:1);
    cout<<ta<<endl<<n/p<<" "<<n%p;
    return 0;
}
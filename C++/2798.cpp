#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int result=-1;
    int list[101];
    for(int i=0;i<n;i++)
        cin>>list[i];
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int z=j+1;z<n;z++){
                if((list[i]+list[j]+list[z]-m)>0)
                    if(list[i]+list[j]+list[z]>result) result=list[i]+list[j]+list[z];
            }
        }
    }
    cout<<result;
    return 0;
}
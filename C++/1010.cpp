#include <iostream>

using namespace std;

int main(){
    int m, n, t;
    cin>>t;

    for(int i=0; i<t;i++)
    {
        long long result=1;
        
        cin>>n>>m;

        for(int j=0; j<n;j++)
        {
            result*=m-j;
            result/=1+j;
        }
        
        cout<<result<<endl;
    }
    return 0;
}
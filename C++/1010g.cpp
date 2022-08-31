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
            //조합. (nCr=n!/r!)
            result*=m-j; //(n-r+1)(n-r+2)...n
            result/=1+j; //r!
        }
        
        cout<<result<<endl;
    }
    return 0;
}
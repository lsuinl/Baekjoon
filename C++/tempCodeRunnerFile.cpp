#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //절사평균. 위15, 아래 15퍼센트 제외. 모두 반올림으로.
    //ceil
    int n, result =0,cut=0;
    cin>>n;
    cut = n/100.0 * 15+0.5;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(i<cut || i>(n-cut-1))
            continue;
        result+=a;
    }
    cout<<result<<endl;
    result = ceil((result*(1.0))/(n-(cut*2.0)));
    cout<<result;
    return 0;
}

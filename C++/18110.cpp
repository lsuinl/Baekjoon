#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a<b;
}
int main(){
    //절사평균. 위15, 아래 15퍼센트 제외. 모두 반올림으로.
    //ceil
    int n;
    float result =0,cut=0;
    cin>>n;

    if( n==0){
        cout<<0;
        return 0;
    }

    int* arr = new int[n];
    cut = floor(n/100.0 * 15+0.5);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n,compare);
    for(int i=cut;i<(n-cut);i++)
        result +=arr[i];
    result = floor(result/(n-(cut*2.0))+0.5);
    cout<<result;
    return 0;
}
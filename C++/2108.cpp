#include <iostream>
#include <algorithm>
using namespace std;

int check[8001]={0,};

bool compare(int a, int b){
    a= a > 0 ? a: abs(a)+4000;
    b= b > 0 ? b: abs(b)+4000;
    return check[a]>check[b];
}

int main(){
    int n;
    cin>>n;

    int suin[n];
    int san=0,bin;
    int min=4001, max=-4001;
    for(int i=0;i<n;i++){
        cin>>suin[i];
        san+=suin[i];
        max= max>suin[i] ? max:suin[i];
        min= min>suin[i] ? suin[i]:min;
        if(suin[i]<0)
            check[abs(suin[i])+4000]++;
        else   
            check[suin[i]]++;
    }

    //산술평균
    san= san/n< float(san/n) ? san/n+1:san/n;
    // //중앙값
    sort(suin,suin+n);
    int middle=suin[n/2];
    // //최빈값
    sort(suin,suin+n,compare);  
    if(check[suin[0]]==check[suin[1]]){
        bin=suin[0];
    }
    else{
        bin=suin[0];
    }
    //범위
    int bound=max-min;
    cout<<san<<"\n"<<middle<<"\n"<<bin<<"\n"<<bound;
    // cout<<san<<"\n"<<middle<<"\n"<<bin<<"\n"<<bound;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;


int hi(int suin[1000], int n);

int main(){
    int n;

    cin>>n;
    int suin[1000];

    for(int i=0;i<n;i++){
        cin>>suin[i];
    }

    cout<<hi(suin,n);

    return 0;
} 
//배열을 만들어서 숫자를 입력받고 작은 순서대로 정렬, 그 후에 차례대로 합을 구해서 출력하기

int hi(int suin[1000], int n){
    sort(suin,suin+n); //오름차순 정렬
    
    int result=suin[0];
    
    for(int i=1;i<n;i++){
        suin[i]=suin[i-1]+suin[i];
        result+=suin[i];
    }

    return result; //결과출력
}

#include <iostream>

using namespace std;

int main(){
    int number[1001], k=1;
 
    for(int i=1;i<=1000;i++){ //1~1000까지의 숫자
        for(int j=1;j<=i;j++){
            number[k]=i; //1~1000까지의 숫자를 1씩 증가하면서 반복해서 넣어주기,,응?
            if(k>1000){
                break; //배열이 모두 차면 for문 빠져나오기
            }
            k++; 
        }
    }


    int a, b, result=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){ //합해서 출력
        result+=number[i];
    }
    cout<<result;

}
#include <iostream>

using namespace std;

int main(){
    int n,result=0;
    int list[200000];
    pair<int,int> num1={0,0}, num2={0,0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(num1.first==list[i])
            num1.second++;
        else if(num2.first==list[i])
            num2.second++;
        else if(num1.first==0)
            num1={list[i],1};
        else if(num2.first==0){
            num2={list[i],1};
        }
        else{ //연속적 내용이 끝난 경우
            result=(num1.second+num2.second)>result?(num1.second+num2.second):result;
            int num=list[i-1], count =0;
            for(int j=i-1;j>=0;j--){
                if(num==list[j]) count++;
                else break;
            }
            num1={num,count};
            num2={list[i],1};
        }
    }
    result=(num1.second+num2.second)>result?(num1.second+num2.second):result;
    cout<<result;
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int repeat(int x, int result){
    if(x==1)
        return result;

    int res = repeat(x-1,result+1);
    if(x%3==0)
        res =  min(res,repeat(x/3, result+1));
    if(x%2 ==0)
        res= min(res,repeat(x/2, result+1));
    return res;
}

int main(){
    int x,result=0;
    cin>>x;
    cout<<repeat(x,0);
    return 0;
}
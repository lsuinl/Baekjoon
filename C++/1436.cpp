#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,result=666;
    cin>>n;
    std::string num=to_string(result);
    while(1){
        if(num.find("666")!=string::npos){
            n--;
            if(n==0) break;
        }
        result++;
         num=to_string(result);
    }
    cout<<result;
    return 0;
}
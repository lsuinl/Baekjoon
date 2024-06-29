#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int result=n-60;
    while(1){
        result++;
        int box = result;
        string num = to_string(result);
        for(int i=0;i<num.size();i++){
            box += num[i]-'0';
            if(box>n) break;
        }
        if(box==n)break;
        else if(result>n) {
            result =0;
            break;
        }
    }
    cout<<result;
    return 0;
}
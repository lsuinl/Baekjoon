#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    string word[N];

    for(int i=0;i<N;i++)
        cin>>word[i];
    
    int result=0;
    bool check=false;
    for(int i=0;i<word[0].length();i++){
        char suin=word[0][i]; //공통접두사 하나씩 검사 
        for(int j=1;j<N;j++){
            if(suin!=word[j][i]){//공통접두사가 아니게되는 순간
                check=true;
                break;
            }
        }
        if(check) break; 
        else result++;
    }
    for(int i=0;i<result;i++){
        cout<<word[0][i];
    }
    return 0;
}
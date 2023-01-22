#include <iostream>
//아나그램이 되는 부분문자열의 개수 구하기.
using namespace std;
int abc[2][52]={0,};

int check(char a){
    if(a>96) return a-97+26;
    else return a-65;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int result=0;
    string suin, word;
    cin>>suin>>word;
    for(int i=0;i<word.size();i++){
        abc[0][check(word[i])]++; //비교단어.
        abc[1][check(suin[i])]++; //원문의 처음부분
    }
    for(int i=0;i<suin.size()-word.size()+1;i++){
        for(int j=0;j<=52;j++){
            if(abc[0][j]!=abc[1][j]){
                break;
            }
            else if(j==51&&(abc[0][j]==abc[1][j])){
                result++;
            }
        }
        abc[1][check(suin[i])]--;
        abc[1][check(suin[i+word.size()])]++;
    }

    cout<<result;
    return 0;
}
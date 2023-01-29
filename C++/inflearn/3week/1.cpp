#include <iostream>
#include <string>
#include <locale>
#include <cctype>

//https://hoho325.tistory.com/315
//https://roadtosuccess.tistory.com/82
using namespace std;

int main(){
    locale e;
    int N;
    char a;
    cin>>N>>a;
    a= toupper(a,e);

    for(int i=0;i<N;i++){
        string word;
        cin>>word;
        for(char& ch : word){
            ch=toupper(ch,e);
        }
        if(word.find(a)!=string::npos){
            string res="";
			for(int i=0; i<word.size(); i++){
				if(word.find(word[i])==i) res+=word[i];
			}
			cout<<res<<endl;
        }
    }
    return 0;
}

//unique(a,b) 문자열의 a번부터 b까지 중복되는 값들을 제거함
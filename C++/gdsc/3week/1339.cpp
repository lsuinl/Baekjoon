#include <iostream>
#include <string>
#include <vector>
#include <math.h>
//https://ongveloper.tistory.com/173
//ㅜㅜ

using namespace std;

int main()
{
    int N, length = 0, result = 0, insert = 9;
    int abc[27] = {
        1,
    }; // 0번째만 1로
    cin >> N;
    vector<string> word;
    
    for (int i = 0; i < N; i++)//입력받기
    {
        string n;
        cin >> n;
        word.push_back(n);
        length = n.length() > length ? n.length() : length;
    }
    
    for (int i=0;i<word.size();i++) //부족한 길이는 골뱅이를 만들어줘요.
    {
        int shor =  length - word[i].length();
        while(shor!=0){
            word[i].insert(word[i].begin(),'@');
            shor--;
        }
    }
    for(int i=0;i<length;i++){ //알파벳 숫자로 변형
        for (int j=0;j<word.size();j++) {
            if(abc[word[j][i]-64]==0){
                abc[word[j][i]-64]=insert;
                insert--;
            }
        }
    }

    abc[0]=0;
    for(int i=0;i<length;i++){ //계산하기
        for (auto w : word) {
            result+=abc[w[i]-64]*pow(10,(length-i-1));
        }
    }
    cout<<result;
    return 0;
}
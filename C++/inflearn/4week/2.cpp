#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string word;
    map<int, int> abc;
    locale e;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    { // 대문자만들기
        word[i] = toupper(word[i], e);
    }

    for (int i = 0; i < word.size(); i++)
    { 
    }
    // 하나씩 중복검사를해
    // 중복이 있다!, 나중이 이득일까 이전이이득일까.
    // 내 다음 알파벳이 좀 더 나중순위다: 이전이이득
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    int abc[26] = {
        0,
    };
    locale e;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    { // 대문자만들기
        word[i] = toupper(word[i], e);
    }
    for (int i = 0; i < word.size(); i++)
    { // 대문자만들기
        if (abc[word[i] - 65] == 0)
        {
            abc[word[i] - 65] = i; //==해당 좌표에있는 문자의정체
        }
        else
        {
            if (word[i + 1] < word[i])
            { // 해당좌표의문자 옆.
            }
        }
    }
    // 하나씩 중복검사를해
    // 중복이 있다!, 나중이 이득일까 이전이이득일까.
    // 내 다음 알파벳이 좀 더 나중순위다: 이전이이득
    return 0;
}
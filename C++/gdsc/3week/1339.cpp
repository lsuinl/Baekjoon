#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int main()
{
    int N, length = 0, result = 0, insert = 9;
    int abc[27][2]={0,}; // 0번: insert넣을 공간 / 1번: 높은 수 구별할 때 쓸 공간
    cin >> N;
    vector<string> word;
    set<int> suin;

    for (int i = 0; i < N; i++) // 입력받기
    {
        string n;
        cin >> n;
        word.push_back(n);
        length = n.length() > length ? n.length() : length;
    }

    for (int i = 0; i < word.size(); i++) // 가장 높은 수(?)를 구별할수있게 만들어놓아요.
    {
        for (int j = 0; j < word[i].size(); j++)
        {
            abc[word[i][j] - 64][1] += 1*pow(10, word[i].size()-j-1);
            suin.insert(word[i][j] - 64);
        }
    }

    for (int i = 0; i < suin.size(); i++)
    {
        int max = 0;
        int cmp = 0;
        for(auto a : suin)
        {
            if (cmp < abc[a][1] && abc[a][0] == 0)
            {
                cmp = abc[a][1];
                max = a;
            }
        }
        abc[max][0] = insert;
        insert--;
    }
    //최종 덧셈.
    for(int i=0;i<word.size();i++){
        for(int j=0;j<word[i].size();j++){
            result+=abc[word[i][j]-64][0]*pow(10, word[i].size()-j-1);
        }
    }

    cout << result;
    return 0;
}
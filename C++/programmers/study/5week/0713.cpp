#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
// V2ooooooooooo1V
// oooooooooo1ooV2o
//
string solution(string s, string skip, int index)
{
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < skip.size(); j++)
            map[skip[j]] = 1;

        for (int j = 0; j < index; j++)
        {
            s[i] += 1; // 일단 넘기기
            if (s[i] > 122)
            {
                s[i] = 97;
                for (int j = 0; j < skip.size(); j++)
                    map[skip[j]] = 1;
            }
            while (1)
            {

                if (map[s[i]] == 1)
                {
                    map[s[i]] = 0;
                    s[i] += 1; // 넘기기
                    if (s[i] > 122)
                    {
                        s[i] = 97;
                        for (int j = 0; j < skip.size(); j++)
                            map[skip[j]] = 1;
                    }
                }
                else
                    break;
            }
        }
    }
    return s;
}

int main()
{
    string s = "aukks";
    string skip = "wbqd";
    int index = 5;
    solution(s, skip, index);
    return 0;
}
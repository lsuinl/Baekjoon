#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<char> abc;
vector<int> gather;
int l, c;

void password(int st, string s, int count)
{
    if (s.length() == l && count != 0 && l - count > 1)
        cout << s << "\n";
    else
    {
        for (int i = st + 1; i < c; i++)
        {
            // 모음체크
            if (abc[i] == 'i' || abc[i] == 'a' || abc[i] == 'e' || abc[i] == 'o' || abc[i] == 'u')
            {
                password(i, s + abc[i], count + 1);
            }
            else
                password(i, s + abc[i], count);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> l >> c;
    abc.resize(c);
    for (int i = 0; i < c; i++)
    {
        cin >> abc[i];
    }
    sort(abc.begin(), abc.end());

    string s;
    password(-1, s, 0);
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

bool english(char s)
{
    if ((s > 64 && s < 91) || (s > 96 && s < 123))
        return true;
        
    return false;
}

int main()
{
    string line;
    getline(cin, line);
    int i, result = 0;
    for (i = 0; i < line.length(); i++)
    {
        if (english(line[i]))
        {
            result++;
            break;
        }
    }

    for (i += 1; i < line.length(); i++)
    {
        if (line[i] == ' ' && english(line[i + 1]))
        {
            result++;
        }
    }
    cout << result;

    return 0;
}
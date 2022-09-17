#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)){ //여기 중요
        int small = 0, big = 0, number = 0, nul = 0;
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == ' ')
                nul++;
            else if (line[j] > 64 && line[j] < 91)
                big++;
            else if (line[j] > 96 && line[j] < 123)
                small++;
            else
                number++;
        }
        cout << small << " " << big << " " << number << " " << nul << "\n";
    }
    return 0;
}
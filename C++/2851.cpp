#include <iostream>

using namespace std;

int main()
{

    int result = 0;
    int mushroom[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> mushroom[i];
    }
    for (int i = 0; i < 10; i++)
    {
        result += mushroom[i];
        if ((result + mushroom[i + 1]) >= 100)
        {
            result = abs(double(result - 100)) >= abs(double(result + mushroom[i + 1] - 100)) ? result + mushroom[i + 1] : result;
            break;
        }
    }

    cout << result;

    return 0;
}

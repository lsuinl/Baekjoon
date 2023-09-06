#include <string>
#include <vector>
#include <math.h>
using namespace std;

int setnumber(int a, int b)
{
    //int sum = abs(b-a);
    // switch (sum)
    // {
    //     case 0:
    //         return 0;
    // case 1:
    // case 3:
    //     return 1;
    //     break;
    // case 2:
    // case 4:
    // case 6:
    //     return 2;
    // case 9:
    // case 5:
    // case 7:
    //     return 3;
    // default:
    //     return 4;
    // }
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int l = 10, r = 12;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            numbers[i] = 11;
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            l = numbers[i];
            answer.push_back('L');
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            r = numbers[i];
            answer.push_back('R');
        }
        else
        {
            int lnumber = setnumber(l, numbers[i]);
            int rnumber = setnumber(r, numbers[i]);
            if (lnumber == rnumber)
            {
                if (hand == "right")
                {
                    r = numbers[i];
                    answer.push_back('R');
                }
                else
                {
                    l = numbers[i];
                    answer.push_back('L');
                }
            }
            else if (lnumber > rnumber)
            {
                r = numbers[i];
                answer.push_back('R');
            }
            else
            {
                l = numbers[i];
                answer.push_back('L');
            }
        }
    }
    return answer;
}
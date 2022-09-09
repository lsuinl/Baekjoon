#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c, d, minn, maxx;
    int team1, team2;
    cin >> a >> b >> c >> d;
    minn = min(min(a, b), min(c, d));
    maxx = max(max(a, b), max(c, d));
    team1 = minn + maxx;
    team2 = (a + b + c + d) - team1;

    cout << abs(team1 - team2);
}
